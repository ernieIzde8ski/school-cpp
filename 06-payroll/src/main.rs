mod ernie;

fn main() {
    let name: String = ernie::input("Input employee name:\t");
    let hours_worked: f32 = ernie::input("Input hours worked:\t");
    let pay_rate: f32 = ernie::input("Input hourly pay rate:\t");

    println!("\nGross pay for '{}': {}", name, hours_worked * pay_rate);
}
