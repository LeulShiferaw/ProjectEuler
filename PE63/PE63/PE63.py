#Only check from 1**X to 9**X
#Because after that the number of digits exceed the exponent
res = 0
curr = 1
while True:
    for j in range(1, 10):
        if len(str(j**curr)) == curr:
            res+=1
    curr+=1
    print(res)
