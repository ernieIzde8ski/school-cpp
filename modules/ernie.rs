use std::fmt;
use std::io;
use std::io::Write;
use std::str;

pub fn input<T: str::FromStr>(prompt: &str) -> T
where
    <T as str::FromStr>::Err: fmt::Debug,
{
    let mut resp: String = String::new();
    print!("{}", prompt);
    if io::stdout().flush().is_err() {
        panic!("stdout fail");
    };
    io::stdin().read_line(&mut resp).expect("readline fail");
    return resp.trim().parse().expect("parse fail");
}
