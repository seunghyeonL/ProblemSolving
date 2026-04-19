import sys

a, b = sys.stdin.readline().rstrip().split()

A = a[::-1]
B = b[::-1]
        
print(max(A, B))