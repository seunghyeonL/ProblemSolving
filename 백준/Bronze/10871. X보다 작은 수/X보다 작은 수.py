import sys

N, X = map(int, sys.stdin.readline().rstrip().split())

arr_map = map(int, sys.stdin.readline().rstrip().split())
arr_list = list(arr_map)
for i in range(N) : 
    if arr_list[i] < X : print(arr_list[i], end = ' ')  