use crate::gen_files::Context;

//  -------------
//      cpp

pub(crate) fn get_full_name(context: &Context) -> String {
    format!(
        "{}/gen_fsm_{}.cpp",
        context.in_file.dir, context.in_file.stem_name
    )
}
