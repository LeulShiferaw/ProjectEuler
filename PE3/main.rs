use std::cmp::max;

fn is_prime(n : u64) -> bool {
    if n == 2 {
        return true;
    }

    if n % 2 == 0 { 
        return false;
    }

    let tmp : f64 = n as f64;
    let lim : u64 = tmp.sqrt() as u64;
    let mut i : u64 = 3;
    while i <= lim {
        if n % i == 0 {
            return false;
        }
        i+=2;
    }
    return true;
}

fn main() {
    let num : f64 = 600851475143.0;
    let sqrt_num : u64 = num.sqrt() as u64;

    let mut i : u64 = 2;
    let mut soln : u64 = 0;
    while i <= sqrt_num {
        if (num as u64) % i != 0 {
            i += 1;
            continue;
        }

        let num1 = i;
        let num2 = (num as u64) / i;

        if is_prime(num1)  {
            soln = max(soln, num1);
        }

        if is_prime(num2) {
            soln = max(soln, num2);
        }

        i += 1;
    }

    println!("{soln}");
}