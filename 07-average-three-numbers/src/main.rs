mod ernie;


fn main() {
    let x: f32 = ernie::input("Input first number:\t");
    let y: f32 = ernie::input("Input second number:\t");
    let z: f32 = ernie::input("Input third number:\t");

    println!("Average of [{}, {}, {}]:\t{}", x, y, z, (x+y+z)/3.0);
}
