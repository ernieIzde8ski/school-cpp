mod ernie;

fn main() {
    let x: f32 = ernie::input("enter 1st number: ");
    let y: f32 = ernie::input("enter 2nd number: ");

    if y == 0.0 {
        panic!("cannot divide by zero");
    } else {
        println!("{} / {} = {}", x, y, x / y);
    }
}
