mod file;
mod parser;

extern crate chrono;
extern crate rayon;

extern crate structopt;
use rayon::prelude::*;

use std::path::PathBuf;
use structopt::StructOpt;

macro_rules! enum_str {
    (enum $name:ident {
        $($variant:ident = $val:expr),*,
    }) => {
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
        match opt.fsm_files.par_iter().try_for_each(|f| {
            file::process(&f).map_err(|e| format!("error processing file: {:?}\n\n{}", f, e))
        }) {
            Ok(()) => (),
            Err(e) => eprintln!("{}", e),
        };
        println!("File generation finished.");
    }
}

// fn main() {
//     let parsed = parser::parse(
//         r#"
//         [init]
//             rq_key                  -   send_key        ->  w_login
//             rq_login                -   log_err         ->  logout
//             rq_logout               -   log_err         ->  logout
//             heartbeat               -   log_err         ->  logout
//             timer                   -   log_err         ->  logout

//         [w_login]
//             rq_key                  -   log_err         ->  logout
//             rq_login    &   valid   -   send_login      ->  login
//             rq_login                -   log_err         ->  logout
//             rq_logout               -   log_err         ->  logout
//             heartbeat               -   log_err         ->  logout
//             timer                   -                   ->  logout

//         [login]
//             rq_key                  -   log_err         ->  logout
//             rq_login                -   log_err         ->  logout
//             rq_logout               -   send_logout     ->  logout
//             heartbeat               -   log_err         ->  logout
//             timer       &   on_time -                   ->  login
//             timer                   -                   ->  logout

//         [logout]
//             rq_key                  -   log_err         ->  logout
//             rq_login                -   log_err         ->  logout
//             rq_logout               -   logout          ->  logout
//             heartbeat               -   log_err         ->  logout
//             timer                   -   log_err         ->  logout
//     "#,
//     );

//     println!("parsed {:#?}", parsed);
// }

//  [
//     Status {
//         name: "init",
//         transitions: [
//             Transition {
//                 input: "rq_key",
//                 guard: None,
//                 action: Some(
//                     "send_key"
//                 ),
//                 new_status: "w_login"
//             },
//             Transition {
//                 input: "rq_login",
//                 guard: None,
//                 action: Some(
//                     "log_err"
//                 ),
//                 new_status: "logout"
//             },
//             Transition {
//                 input: "rq_logout",
//                 guard: None,
//                 action: Some(
//                     "log_err"
//                 ),
//                 new_status: "logout"
//             },
//             Transition {
//                 input: "heartbeat",
//                 guard: None,
//                 action: Some(
//                     "log_err"
//                 ),
//                 new_status: "logout"
//             },
//             Transition {
//                 input: "timer",
//                 guard: None,
//                 action: Some(
//                     "log_err"
//                 ),
//                 new_status: "logout"
//             }
//         ]
//     },
//     Status {
//         name: "w_login",
//         transitions: [
//             Transition {
//                 input: "rq_key",
//                 guard: None,
//                 action: Some(
//                     "log_err"
//                 ),
//                 new_status: "logout"
//             },
//             Transition {
//                 input: "rq_login",
//                 guard: Some(
//                     "valid"
//                 ),
//                 action: Some(
//                     "send_login"
//                 ),
//                 new_status: "login"
//             },
//             Transition {
//                 input: "rq_login",
//                 guard: None,
//                 action: Some(
//                     "log_err"
//                 ),
//                 new_status: "logout"
//             },
//             Transition {
//                 input: "rq_logout",
//                 guard: None,
//                 action: Some(
//                     "log_err"
//                 ),
//                 new_status: "logout"
//             },
//             Transition {
//                 input: "heartbeat",
//                 guard: None,
//                 action: Some(
//                     "log_err"
//                 ),
//                 new_status: "logout"
//             },
//             Transition {
//                 input: "timer",
//                 guard: None,
//                 action: None,
//                 new_status: "logout"
//             }
//         ]
//     },
//     Status {
//         name: "login",
//         transitions: [
//             Transition {
//                 input: "rq_key",
//                 guard: None,
//                 action: Some(
//                     "log_err"
//                 ),
//                 new_status: "logout"
//             },
//             Transition {
//                 input: "rq_login",
//                 guard: None,
//                 action: Some(
//                     "log_err"
//                 ),
//                 new_status: "logout"
//             },
//             Transition {
//                 input: "rq_logout",
//                 guard: None,
//                 action: Some(
//                     "send_logout"
//                 ),
//                 new_status: "logout"
//             },
//             Transition {
//                 input: "heartbeat",
//                 guard: None,
//                 action: Some(
//                     "log_err"
//                 ),
//                 new_status: "logout"
//             },
//             Transition {
//                 input: "timer",
//                 guard: Some(
//                     "on_time"
//                 ),
//                 action: None,
//                 new_status: "login"
//             },
//             Transition {
//                 input: "timer",
//                 guard: None,
//                 action: None,
//                 new_status: "logout"
//             }
//         ]
//     },
//     Status {
//         name: "logout",
//         transitions: [
//             Transition {
//                 input: "rq_key",
//                 guard: None,
//                 action: Some(
//                     "log_err"
//                 ),
//                 new_status: "logout"
//             },
//             Transition {
//                 input: "rq_login",
//                 guard: None,
//                 action: Some(
//                     "log_err"
//                 ),
//                 new_status: "logout"
//             },
//             Transition {
//                 input: "rq_logout",
//                 guard: None,
//                 action: Some(
//                     "logout"
//                 ),
//                 new_status: "logout"
//             },
//             Transition {
//                 input: "heartbeat",
//                 guard: None,
//                 action: Some(
//                     "log_err"
//                 ),
//                 new_status: "logout"
//             },
//             Transition {
//                 input: "timer",
//                 guard: None,
//                 action: Some(
//                     "log_err"
//                 ),
//                 new_status: "logout"
//             }
//         ]
//     }
// ]
