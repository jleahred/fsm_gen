use std::path::PathBuf;
use structopt::StructOpt;

#[macro_use]
mod support;

enum_str! {
    enum Lang {
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
pub(crate) struct Opt {
    /// Language to generate code (show available --show-langs)
    #[structopt(short = "l", long = "lang", default_value = "cpp")]
    pub(crate) lang: Lang,

    // /// Generate all files regardless of change date
    // #[structopt(short = "f", long = "force")]
    // force: bool,
    //
    /// Number of threads to use. 0 means one per core  ;-)
    #[structopt(short = "t", long = "threads", default_value = "0")]
    pub(crate) n_threads: usize,

    ///  Show supported languages generators
    #[structopt(short = "s", long = "show-langs")]
    pub(crate) show_langs: bool,

    ///  Generate graphviz dot file
    #[structopt(short = "d", long = "dot-graphviz")]
    pub(crate) dot: bool,

    /// List of fsm files
    #[structopt(parse(from_os_str))]
    pub(crate) fsm_files: Vec<PathBuf>,

    /// Give me some information about generating cpp files
    #[structopt(long = "help-cpp")]
    pub(crate) help_cpp: bool,
}
