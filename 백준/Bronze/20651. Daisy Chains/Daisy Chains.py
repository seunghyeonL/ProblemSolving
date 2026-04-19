import sys

N = int(sys.stdin.readline().rstrip())
flower_map = map(int, sys.stdin.readline().rstrip().split())
flower_list = list(flower_map)

cnt = 0

for i in range(N) :
    for j in range(i, N) :
        avg = 0
        for k in range(i, j+1) :
            avg += flower_list[k]
        avg = avg/(j+1-i)    
        for k in range(i, j+1) :
            if avg == flower_list[k] :
                cnt += 1
                break

                
print(cnt)   