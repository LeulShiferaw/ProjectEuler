import math

def num_dig(n):
    x = n
    return math.floor(math.log(x, 10)) + 1

nr = 1
dr = 2
res = 0
for i in range(1000):
    n = dr+nr
    d = dr

    if(num_dig(n)>num_dig(d)):
        res+=1
        
    temp = nr     
    nr = dr
    dr = 2*dr + temp

print(res)
