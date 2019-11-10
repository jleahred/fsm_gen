mod file;
mod parser;

extern crate chrono;
extern crate rayon;
use rayon::prelude::*;
extern crate structopt;
use structopt::StructOpt;

use std::path::PathBuf;

macro_rules! enum_str {
    (enum $name:ident {
        $($variant:ident = $val:expr),*,
    }) => {
        #[derive(PartialEq)]
        enum $name {
            $($variant),*
        }

        impl std::str::FromStr for Langs {
            type Err = String;
            fn from_str(s: &str) -> Result<Langs, String> {
                match s {
                    $($val => Ok($name::$variant)),*,
                    _ => Err(format!("Language not supported (yet) -> {}\nsupported languages (at the moment): {}", s, Langs::get_options_as_string())),
                }
            }
        }

        impl std::fmt::Debug for $name {
            fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
                match self {
                    $($name::$variant => write!(f, "{}", $val)),*
                }
            }
        }

        impl $name {
            fn get_options_as_string() -> String {
                let mut s = String::new();
                $(s = format!("{}  {} ", s, $val);),*
                s
            }
        }

    };
}

enum_str! {
    enum Langs {
        Cpp = "cpp",
    }
}

#[derive(Debug, StructOpt)]
#[structopt(
    name = "fsm_gen",
    about = r#"
    Generate code from a simple fsm file
    To check the supported languages  --show_langs
    "#
)]
struct Opt {
    /// Language to generate code (show available --show-langs)
    #[structopt(short = "l", long = "lang", default_value = "cpp")]
    lang: Langs,

    // /// Generate all files regardless of change date
    // #[structopt(short = "f", long = "force")]
    // force: bool,
    /// Number of threads to use. 0 means all
    #[structopt(short = "t", long = "threads", default_value = "0")]
    n_threads: usize,

    ///  Show supported languages generators
    #[structopt(short = "s", long = "show-langs")]
    show_langs: bool,

    ///  Generate graphviz dot file
    #[structopt(short = "d", long = "dot-graphviz")]
    dot: bool,

    /// List of fsm files
    #[structopt(parse(from_os_str))]
    fsm_files: Vec<PathBuf>,

    /// Give me some information about generating cpp files
    #[structopt(long = "help-cpp")]
    help_cpp: bool,
}

fn main() {
    let opt = Opt::from_args();

    if opt.show_langs {
        println!(
            "\nSupported languages: {}\n\n",
            Langs::get_options_as_string()
        );
    } else if opt.help_cpp {
        file::cpp::print_cpp_help_message();
    } else if opt.fsm_files.is_empty() {
        eprintln!("No files provied!!! If doubt,  --help");
    } else {
        if opt.n_threads != 0 {
            rayon::ThreadPoolBuilder::new()
                .num_threads(opt.n_threads)
                .build_global()
                .unwrap();
        }
        let config = file::Config {
            lang: opt.lang,
            dot: opt.dot,
        };
        match opt.fsm_files.par_iter().try_for_each(|f| {
            file::process(&f, &config)
                .map_err(|e| format!("error processing file: {:?}\n\n{}", f, e))
        }) {
            Ok(()) => (),
            Err(e) => eprintln!("{}", e),
        };
        println!("File generation finished.");
    }
}

// mod parser;

// fn main() {
//     let parsed = parser::parse(
//         r#"
//         [init]
//             rq_key          ->  w_login     /   send_key
//             timer           ->  init

//         [w_login]
//             rq_login        ->  login       /   send_login

//             timer
//                 timeout     ->  error
//                             ->  w_login

//         [login]
//             rq_logout       ->  logout      /   send_logout
//             heartbeat       ->  login       /   update_hb
//             timer
//                 timeout     ->  logout
//                             ->  login

//         [logout]
//             timer           ->  logout

//         [error]
//             _               ->  error
//     "#,
//     );
//     match parsed {
//         Ok(fsm) => println!("parsed {:#?}", fsm),
//         Err(err) => println!("Error!! {}", err),
//     }
// }

// mod parser;

// fn main() {
//     let parsed = parser::parse(
//         r#"
//         //  iceberg
//         //
//         //  inputs:
//         //      client
//         //          rq_nw
//         //          rq_md
//         //          rq_cc
//         //      server
//         //          cf_nw
//         //          cf_cc
//         //          cf_ex

//          [init]
//             rq_nw               ->  w_cf_nw                 /   send_rq_nw

//         [w_cf_nw]
//             cf_nw               ->  market

//             timer
//                 timeout         ->  error                   /   send_rq_cc
//                                 ->  w_cf_nw                 /   send_rq_cc
//             rq_md               ->  modifying_w_nw
//             rq_cc               ->  canceling_w_nw

//         [modifying_w_nw]
//             cf_nw               ->  w_cf_nw                 /   send_rq_nw
//             rq_md               ->  modifying_w_nw
//             rq_cc               ->  canceling_w_nw
//             cf_cc               ->  error                   /   send_rq_cc
//             cf_ex               ->  error                   /   send_cf_ex
//             timer
//                 timeout         ->  error                   /   send_rq_cc
//                                 ->  modifying_w_nw

//         [canceling_w_nw]
//             rq_md               ->  canceling_w_nw          /   send_rj_md
//             rq_cc               ->  canceling_w_nw          /   send_rq_cc
//             cf_cc               ->  error                   /   send_rq_cc
//             cf_ex               ->  error                   /   send_cf_ex send_rq_cc
//             timer
//                 timeout         ->  error                   /   send_rq_cc
//                                 ->  canceling_w_nw

//         [market]
//             cf_ex
//                 partial         ->  market                  /   send_cf_ex
//                                 ->  end                     /   send_cf_ex
//             rq_md               ->  modifying_w_cc          /   send_rq_cc
//             rq_cc               ->  canceling_w_cc          /   send_rq_cc

//         [modifying_w_cc]
//             cf_cc               ->  w_cf_nw                 /   send_rq_nw
//             cf_ex
//                 partial         ->  modifying_w_cc          /   send_cf_ex
//                                 ->  end                     /   send_cf_ex
//             rq_md               ->  modifying_w_cc
//             rq_cc               ->  canceling_w_cc
//             timer
//                 timeout         ->  error                   /   send_rq_cc
//                                 ->  modifying_w_cc

//         [canceling_w_cc]
//             cf_cc               ->  end                     /   send_rq_nw
//             cf_ex
//                 partial         ->  canceling_w_cc          /   send_cf_ex
//                                 ->  end                     /   send_cf_ex
//             rq_md               ->  canceling_w_cc          /   send_rj_md
//             rq_cc               ->  canceling_w_cc
//             timer
//                 timeout         ->  error                   /   send_rq_cc
//                                 ->  canceling_w_cc

//         [end]
//             _                           ->  error

//         [error]
//             _                           ->  error2          /   try_send_cc

//         [error2]
//             _                           ->  error2
//     "#,
//     );

//     match parsed {
//         Ok(fsm) => println!("parsed {:#?}", fsm),
//         Err(err) => println!("Error!! {}", err),
//     }
// }
