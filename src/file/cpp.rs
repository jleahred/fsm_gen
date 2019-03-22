use std::path::PathBuf;

mod cpp_file;
mod cpp_gen_file;
mod h_file;
mod h_gen_file;

pub(crate) fn generate_cpp_files(
    fsm: &[crate::parser::Status],
    orig_path: &PathBuf,
) -> std::result::Result<(), String> {
    h_gen_file::generate_header_fsm_code_generated(fsm, orig_path).map_err(|e| e.to_string())?;
    cpp_gen_file::generate_cpp_fsm_code_generated(fsm, orig_path).map_err(|e| e.to_string())?;
    h_file::generate_header_fsm_code(fsm, orig_path).map_err(|e| e.to_string())?;
    cpp_file::generate_cpp_fsm_code(fsm, orig_path).map_err(|e| e.to_string())?;
    Ok(())
}
