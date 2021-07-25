import math

p = []
p.append(-1)
p.append(1)

n = 2
while True:
    pn = 1 + p[n-1]
    for i in range(2, math.floor(n/2)+1):
        pn += p[n-i]
        for k in range(1, math.floor((n-i)/2)+1):
            if k >= i:
                break
            pn -= p[n-i-k]
    print(n, pn)
    p.append(pn)
    if pn % 1000000 == 0:
        print(n, pn)
        break
    n+=1
