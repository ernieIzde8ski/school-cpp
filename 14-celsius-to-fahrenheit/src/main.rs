mod ernie;

fn c_to_f(deg_c: f32) -> f32 {
    deg_c * 9.0 / 5.0 + 32.0
}

fn main() {
    let deg_c: f32 = ernie::input("enter degrees in celsius: ");
    println!("{}°C is equal to {}°F", deg_c, c_to_f(deg_c));
}
