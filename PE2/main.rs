fn main() {
    let mut fib1: u32 = 1;
    let mut fibn: u32 = 2;
    let mut sum : u64 = 0;
    loop {
        if fibn > 4000000 {
            break;
        } 

        if fibn % 2 == 0 {
            sum += fibn as u64;
        }

        fibn += fib1;
        fib1 = fibn - fib1;
    }

    println!("{sum}");
}