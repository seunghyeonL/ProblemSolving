import sys

N, M = map(int, sys.stdin.readline().rstrip().split())
arr_map = map(int, sys.stdin.readline().rstrip().split())
arr_list = list(arr_map)

diff_M = M
sum_3 = 0

for i in range(N) : 
    for j in range(i+1, N) :
        for k in range(j+1, N) :
            sum_3 = arr_list[i] + arr_list[j] + arr_list[k]
            if 0 <= M - sum_3 < diff_M :
                diff_M = M - sum_3
                
print(M-diff_M)