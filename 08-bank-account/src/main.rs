mod ernie;

fn main() {
    const INITIAL_BALANCE: f32 = 5000.0;
    let deposit: f32 = ernie::input("Enter deposit sum:\t");
    let withdrawal: f32 = ernie::input("Enter withdrawal sum:\t");
    
    println!();
    println!("Initial balance:\t{}", INITIAL_BALANCE);
    println!("Deposit sum:\t\t{}", deposit);
    println!("Withdrawal sum:\t\t{}", withdrawal);
    println!("Final sum:\t\t{}", INITIAL_BALANCE + deposit - withdrawal);
}
