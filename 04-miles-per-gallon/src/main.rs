use std::{
    fmt,
    io::{self, Write},
    str,
};

fn input<T: str::FromStr>(prompt: &str) -> T
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

fn main() {
    let mileage_initial: f32 = input("Enter initial mileage:\t");
    let mileage_final: f32 = input("Enter final mileage:\t");
    let gallons: f32 = input("Enter gallons consumed:\t");
    println!("\nMiles per gallon: {}", (mileage_final - mileage_initial) / gallons);
}
