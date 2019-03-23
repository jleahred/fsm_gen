use std::fs::File;
use std::io::prelude::*;
use std::path::PathBuf;

pub(crate) mod cpp;

pub(crate) fn process(path: &PathBuf) -> std::result::Result<(), String> {
    let mut file = File::open(path).map_err(|e| format!("{}", e))?;
    let mut contents = String::new();
    file.read_to_string(&mut contents)
        .map_err(|e| format!("{}", e))?;

    let fsm = crate::parser::parse(&contents)?;
    generate_cpp_code(&fsm, &path)?;
    Ok(())
}

fn generate_cpp_code(
    fsm: &[crate::parser::Status],
    orig_path: &PathBuf,
) -> std::result::Result<(), String> {
    cpp::generate_cpp_files(fsm, orig_path).map_err(|e| e.to_string())?;
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
