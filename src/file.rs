use std::fs::File;
use std::io::prelude::*;
use std::path::PathBuf;

pub(crate) mod cpp;
mod dot;

pub(crate) struct Config {
    pub(crate) lang: crate::Langs,
    pub(crate) dot: bool,
}

pub(crate) fn process(path: &PathBuf, config: &Config) -> std::result::Result<(), String> {
    let mut file = File::open(path).map_err(|e| format!("{}", e))?;
    let mut contents = String::new();
    file.read_to_string(&mut contents)
        .map_err(|e| format!("{}", e))?;

    let ast = crate::parser::parse(&contents)?;

    if config.lang == crate::Langs::Cpp {
        cpp::generate_cpp_files(&ast, &path).map_err(|e| e.to_string())?;
    }

    if config.dot {
        dot::generate_file(&ast, &path).map_err(|e| e.to_string())?;
    }
    Ok(())
}

//  -------------
//      support

fn get_dir_stem_name(orig_path: &PathBuf) -> Result<(String, String), String> {
    let to_string = |p: &Option<&str>| -> Result<String, String> {
        Ok(p.ok_or(format!(
            "cannot take original file name from {:?}",
            orig_path
        ))?
        .to_string())
    };

    let dir = {
        let mut dir = orig_path.clone();
        dir.pop();
        dir
    };

    Ok((
        to_string(&dir.to_str())?,
        to_string(&orig_path.file_stem().and_then(|fname| fname.to_str()))?,
    ))
}
