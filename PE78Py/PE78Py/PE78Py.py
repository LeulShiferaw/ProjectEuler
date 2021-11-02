import math
import sys

n = 100000

prev_soln = []
soln = []
for i in range(n+1):
    prev_soln.append(1)
    soln.append(0)

for i in range(2, n+1):
    for j in range(n+1):
        if j < i:
            soln[j] = prev_soln[j]
        else:
            soln[j] = prev_soln[j] +soln[j-i]
        if i == j and soln[j] % 1000000 == 0:
            print(i)
    prev_soln = soln
