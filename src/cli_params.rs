use std::path::PathBuf;
use structopt::StructOpt;

#[macro_use]
mod support;

enum_str! {
    enum Templ {
        Cpp = "cpp",
    }
}

#[derive(Debug, StructOpt)]
#[structopt(
    name = "fsm_gen",
    about = r#"
    Generate code from a simple fsm file
    To check the supported templates  --show_templs
    "#
)]
pub(crate) struct Opt {
    /// Template to generate code (show available --show-templs)
    #[structopt(short = "t", long = "templ", default_value = "cpp")]
    pub(crate) templ: Templ,

    // /// Generate all files regardless of change date
    // #[structopt(short = "f", long = "force")]
    // force: bool,
    //
    /// Number of threads to use. 0 means one per core  ;-)
    #[structopt(short = "T", long = "threads", default_value = "0")]
    pub(crate) n_threads: usize,

    ///  Show supported template generators
    #[structopt(short = "s", long = "show-templs")]
    pub(crate) show_templs: bool,

    ///  Generate graphviz dot file
    #[structopt(short = "d", long = "dot-graphviz")]
    pub(crate) dot: bool,

    /// List of fsm files to be processed
    #[structopt(parse(from_os_str))]
    pub(crate) fsm_files: Vec<PathBuf>,

    /// Give me some information about generating cpp files
    #[structopt(long = "help-cpp")]
    pub(crate) help_cpp: bool,
}
