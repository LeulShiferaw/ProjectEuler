import math

def fac(n):
    res = 1
    for i in range(1, n+1):
        res*=i
    return res

def num_vals(n):
    res = 0
    num = fac(n)
    den = fac(math.floor(n/2)) * fac(n-math.floor((n/2)))
    for i in range(math.floor(n/2), -1, -1):#desending value
        if num/den > 1000000:
            if ((n-i) == i):
                res = res +1
            else:
                res += 2
        else:
            break

        num *= i
        den *= n-i+1

    return res

res = 0
for i in range(1, 101):
    res += num_vals(i)

print(res)

