def fifth_pwr(n):
    res = 0
    while n != 0:
        x = n%10
        res+=x**5
        n=int(n/10)
    return res

res = 0
for i in range(10000000):
    if fifth_pwr(i) == i:
        res+=i
print(res)
