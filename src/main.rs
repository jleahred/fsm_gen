mod file;
mod parser;

extern crate chrono;
extern crate structopt;

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
    name = "fsm",
    about = r#"
    Generate code from a simple fsm file
    To check the supported languages  --show_langs
    "#
)]
struct Opt {
    /// Set language to generate code (at the moment only cpp is supported)
    #[structopt(short = "l", long = "lang", default_value = "cpp")]
    lang: Langs,

    /// Generate all files regardless of change date
    #[structopt(short = "f", long = "force")]
    force: bool,

    ///  Show supported languages generators
    #[structopt(short = "s", long = "show_langs")]
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
        print_cpp_help_message();
    } else if opt.fsm_files.is_empty() {
        eprintln!("No files provied!!! If doubt,  --help");
    } else {
        for f in opt.fsm_files {
            match file::process(&f) {
                Ok(()) => (),
                Err(e) => eprintln!("error processing file: {:?}\n\n{}", f, e),
            }
        }
        println!("File generation finished.");
    }
}

fn print_cpp_help_message() {
    println!(r#"
Being "name.fsm" the name of the file with the definition of the machine, two files will be generated.

    fsm_name_gen.cpp
    fsm_name_gen.h

In them the declarations and definitions of the state machine will be generated.

In fsm_name_gen.h it is indicated with comments, the methods to overwrite manually and the file where it is convenient to do it.

The manual implementation of the methods and declarations of the types, it is recommended to do it in the following files.

    fsm_name_gen.cpp
    fsm_name_gen.h

If they do not exist, they will be created with an empty implementation.
"#);
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
