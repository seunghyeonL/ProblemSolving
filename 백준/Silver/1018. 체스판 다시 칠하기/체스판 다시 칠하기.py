import sys

N, M = map(int, sys.stdin.readline().rstrip().split())

chess_1 = []
chess_2 = []

for i in range(8) : 
    if i%2 == 0 :
        chess_1.append('WBWBWBWB')
        chess_2.append('BWBWBWBW')
    else :
        chess_1.append('BWBWBWBW')
        chess_2.append('WBWBWBWB')
        
chess_ruff = []

for i in range(N) :
    chess_line = sys.stdin.readline().rstrip()
    chess_ruff.append(chess_line)
    
min_1_result = 64
min_2_result = 64

for i in range(N+1-8) :
    for j in range(M+1-8) :
        min_1 = 0
        min_2 = 0
        for k in range(8) :
            for l in range(8) :
                if chess_ruff[i+k][j+l] != chess_1[k][l] :
                    min_1 += 1
                if chess_ruff[i+k][j+l] != chess_2[k][l] :
                    min_2 += 1
        if min_1 < min_1_result :
            min_1_result = min_1
        if min_2 < min_2_result :
            min_2_result = min_2
            
print(min(min_1_result, min_2_result))