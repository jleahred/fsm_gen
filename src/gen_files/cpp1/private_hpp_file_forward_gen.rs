use crate::gen_files::*;

//  -------------
//      cpp

pub(crate) fn get_full_name(context: &Context) -> String {
    format!(
        "{}/gen_fsm_{}_private_forward.hpp",
        context.in_file.dir, context.in_file.stem_name
    )
}
