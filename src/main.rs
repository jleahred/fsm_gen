mod cli_params;
mod file;
mod parser;

extern crate chrono;
extern crate rayon;
extern crate structopt;

use rayon::prelude::*;
use structopt::StructOpt;

fn main() {
    let opt = cli_params::Opt::from_args();

    if opt.show_langs {
        println!(
            "\nSupported languages: {}\n\n",
            cli_params::Langs::get_options_as_string()
        );
    } else if opt.help_cpp {
        file::cpp::print_cpp_help_message();
    } else if opt.fsm_files.is_empty() {
        eprintln!("No files provied!!! If doubt,  --help");
    } else {
        if opt.n_threads != 0 {
            init_rayon(opt.n_threads);
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

fn init_rayon(n_threads: usize) {
    if n_threads != 0 {
        rayon::ThreadPoolBuilder::new()
            .num_threads(n_threads)
            .build_global()
            .unwrap();
    }
}
