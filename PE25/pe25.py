def num_digits(n):
    res = 0
    while n > 0:
        n /= 10
        res += 1
    return res

f1 = 1
fn = 1
ind = 2

while(num_digits(fn) != 1000):
    fn = fn + f1
    f1 = fn - f1
    ind+=1

print(ind)
