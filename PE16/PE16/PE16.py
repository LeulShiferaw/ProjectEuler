two_1000 = 2**1000
str_two_1000 = str(two_1000)

res = 0
for i in range(0, len(str_two_1000)):
    res += int(str_two_1000[i])

print(res)
