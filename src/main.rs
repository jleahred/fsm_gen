extern crate chrono;
extern crate rayon;
extern crate structopt;
extern crate tera;

mod cli_params;
mod config;
mod files;
mod gen_files;
mod parser;

use config::Config;
use rayon::prelude::*;
use structopt::StructOpt;

fn main() {
    let opt = cli_params::Opt::from_args();

    if opt.show_templs {
        println!(
            "\nSupported templates: {}\n\n",
            cli_params::Templ::get_options_as_string()
        );
    } else if opt.help_cpp1 {
        gen_files::cpp1::print_cpp_help_message();
    } else if opt.help_cpp2 {
        gen_files::cpp2::print_cpp_help_message();
    } else if opt.fsm_files.is_empty() {
        eprintln!("No files provied!!! If doubt,  --help");
    } else {
        configure_rayon(opt.n_threads);
        process_files(&opt.fsm_files, opt.templ, opt.dot, opt.force);
    }
}

fn process_files(
    fsm_files: &Vec<std::path::PathBuf>,
    templ: cli_params::Templ,
    dot: bool,
    force: bool,
) {
    let config = Config { templ, dot, force };

    let _ = fsm_files
        .par_iter()
        .try_for_each(|f| {
            gen_files::process(&f, &config)
                .map_err(|e| format!("error processing file: {:?}\n\n{}", f, e))
        })
        .map_err(|e| eprintln!("{}", e));
    println!("File generation finished.");
}

fn init_rayon(n_threads: usize) {
    if n_threads != 0 {
        rayon::ThreadPoolBuilder::new()
            .num_threads(n_threads)
            .build_global()
            .unwrap();
    }
}

fn configure_rayon(n_threads: usize) {
    if n_threads != 0 {
        init_rayon(n_threads);
    }
}
