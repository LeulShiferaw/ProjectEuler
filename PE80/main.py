import math

def findFit(x, y):
    for i in range(0, 10):
        if (x*10+i)*i > y:
            return i-1
    return 9

def sqroot(n):
    x = math.floor(math.sqrt(n))
    bot = n-x*x
    if bot == 0:
        return [0]
    up = x
    res = [x]
    for i in range(99):
        bot *= 100
        side = 2*up
        temp = findFit(side, bot)
        side = side*10 + temp
        up = up*10 + temp
        res.append(temp)
        bot -= side*temp
    return res

sum = 0
for i in range(1, 101):
    curr = sqroot(i)
    for x in curr:
        sum += x
print(sum)
        
