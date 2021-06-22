#PROJECT EULER PROBLEM 55
#LYCHERL NUMBERS
#WRITTEN BY LEUL SHIFERAW
import math

def is_palindrome(n):
    str_n = str(n)
    for i in range(math.floor(len(str_n)/2)+1):
        if str_n[i] != str_n[len(str_n)-1-i]:
            return False
    return True

def reverse(n):
    str_n = str(n)
    rv_str_n = str_n[::-1]
    return int(rv_str_n)

def is_lychrel(n):
    for i in range(49):
        n0 = n+reverse(n)
        n = n0
        if is_palindrome(n0):
            return False
    return True

if is_lychrel(349):
    print("Lychrel")
else:
    print("Not Lychrel")

res = 0
for i in range(10000):
    if is_lychrel(i):
        res = res +1

print(res)