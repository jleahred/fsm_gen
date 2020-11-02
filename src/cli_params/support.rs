macro_rules! enum_str {
    (enum $name:ident {
        $($variant:ident = $val:expr),*,
    }) => {
        #[derive(PartialEq)]
        pub(crate) enum $name {
            $($variant),*
        }

        impl std::str::FromStr for Templ {
            type Err = String;
            fn from_str(s: &str) -> Result<Templ, String> {
                match s {
                    $($val => Ok($name::$variant)),*,
                    _ => Err(format!("Template not supported (yet) -> {}\nsupported templates (at the moment): {}", s, Templ::get_options_as_string())),
                }
            }
        }

        impl std::fmt::Debug for $name {
            fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
                match self {
                    $($name::$variant => write!(f, "{}", $val)),*
                }
            }
        }

        impl $name {
            pub(crate) fn get_options_as_string() -> String {
                let mut s = String::new();
                $(s = format!("{}  {} ", s, $val);),*
                s
            }
        }

    };
}
