import sys

N = int(sys.stdin.readline().rstrip())
arr_list = []
input = 0

for i in range(N) :
    input = int(sys.stdin.readline().rstrip())
    arr_list.append(input)
    
cnt_left = 0
cnt_right = 0
max_left = 0
max_right = 0

for i in range(N) : 
    if max_left < arr_list[i] :
        cnt_left += 1
        max_left = arr_list[i]
    if max_right < arr_list[-1-i] :
        cnt_right += 1
        max_right = arr_list[-1-i]
        
print(cnt_left)
print(cnt_right)