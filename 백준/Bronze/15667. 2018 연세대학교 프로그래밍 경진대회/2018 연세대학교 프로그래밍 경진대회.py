import sys

N = int(sys.stdin.readline().rstrip())
D = 1-4*(1-N)
k = (-1+(D**0.5))/2

print(int(k))