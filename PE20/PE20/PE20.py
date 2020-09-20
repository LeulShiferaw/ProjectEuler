def factorial(n):
    res = 1
    for i in range(n):
        res*=(i+1)
    return res

fac100 = factorial(100)
str_fac100 = str(fac100)

res = 0
for c in str_fac100:
    res += int(c)-int('0')
print(res)
