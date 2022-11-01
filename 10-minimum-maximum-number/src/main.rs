mod ernie;

fn main() {
    let x: f32 = ernie::input("input 1st number: ");
    let y: f32 = ernie::input("input 2nd number: ");
    println!();

    if x < y {
        println!("{} is less than {}", x, y);
    } else if x > y {
        println!("{} is greater than {}", x, y);
    } else if x == y {
        println!("{} is equal to {}", x, y);
    } else {
        println!("either '{}' and/or '{}' is NaN", x, y);
    }
}
