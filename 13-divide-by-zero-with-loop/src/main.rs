mod ernie;

fn main() {
    // define variables
    let x: f32 = ernie::input("input 1st number: ");
    let mut y: f32 = ernie::input("input 2nd number: ");

    // assert y != 0
    while y == 0.0 {
        println!("error: divisor cannot be zero");
        y = ernie::input("re-input 2nd number: ");
    }

    // display division
    println!("{} / {} = {}", x, y, x / y);
}
