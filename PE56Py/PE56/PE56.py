def digit_sum(n):
    x = n
    res = 0
    while x != 0:
        res += (x % 10)
        x//=10
    return res

max_dig_sum = -10
for a in range(1, 101):
    for b in range(1, 101):
        temp = digit_sum(a**b)
        if(temp > max_dig_sum):
            max_dig_sum = temp
            
print(max_dig_sum)