use rand::Rng;
use std::cmp::Ordering;
use std::io;

fn main() {
    println!("Welcome to the Guessing game");
    loop {
        println!("Enter a number:");

        let secret_number = rand::thread_rng().gen_range(1, 101);

        let mut inp = String::new();

        io::stdin().read_line(&mut inp).expect("Error in reading");

        let inp: u32 = inp.trim().parse().expect("Please type a number");

        println!("You Entered: {}", inp);

        match inp.cmp(&secret_number) {
            Ordering::Less => println!("You Lose"),
            Ordering::Greater => println!("You Lose"),
            Ordering::Equal => {
                println!("You Wpn");
                break;
            }
        }
        println!("Secret Number is {}", secret_number);
    }
}
