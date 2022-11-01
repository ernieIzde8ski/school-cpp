use std::io;


fn main() {
    let mut x = String::new();
    let mut y = String::new();
    
    println!("Input first number:    ");
    io::stdin()
        .read_line(&mut x)
        .expect("fail");
    println!("Input second number: ");
    io::stdin()
        .read_line(&mut y)
        .expect("fail");
    
    let x: f32 = x.trim().parse().expect("fail");
    let y: f32 = y.trim().parse().expect("fail");
    
    println!("{} * {} = {}", x, y, x*y);
    println!("{} / {} = {}", x, y, x/y);
    println!("{} + {} = {}", x, y, x+y);
    println!("{} - {} = {}", x, y, x-y);
}
