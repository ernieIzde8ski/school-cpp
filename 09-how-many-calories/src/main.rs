mod ernie;

// this variable is unused
// const COOKIES_PER_BAG: i32 = 40;
const CALORIES_PER_COOKIE: f32 = 300.0;

fn main() {
    let cookies_consumed: f32 = ernie::input("Input total cookies consumed: ");
    println!("Total calories: {}", cookies_consumed * CALORIES_PER_COOKIE);
}
