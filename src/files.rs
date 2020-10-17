use std::fs::File;
use std::io::prelude::*;
use std::path::PathBuf;

pub(crate) fn read_file(path: &PathBuf) -> std::result::Result<String, String> {
    let mut file = File::open(path).map_err(|e| format!("{}", e))?;
    let mut contents = String::new();
    file.read_to_string(&mut contents)
        .map_err(|e| format!("{}", e))?;
    Ok(contents.to_string())
}

pub(crate) fn write_file(full_file_name: &str, content: &str) -> Result<(), String> {
    println!("Generating file... {}", full_file_name);
    let mut f = File::create(full_file_name).map_err(|e| format!("{}", e))?;

    f.write_all(content.as_bytes())
        .map_err(|e| format!("{}", e))?;

    f.sync_all().map_err(|e| format!("{}", e))?;
    Ok(())
}

pub(crate) fn get_dir_stem_name(orig_path: &PathBuf) -> Result<(String, String), String> {
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

    let dir_string = to_string(&dir.to_str())?;
    let dir_string = if dir_string == "" {
        ".".to_string()
    } else {
        dir_string
    };

    Ok((
        dir_string,
        to_string(&orig_path.file_stem().and_then(|fname| fname.to_str()))?,
    ))
}
