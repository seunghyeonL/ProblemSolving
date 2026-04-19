import sys

N = int(sys.stdin.readline().rstrip())
plate = []

for i in range(N) :
    plate_line = sys.stdin.readline().rstrip()
    plate.append(plate_line)

head = (0, 0)
for i in range(N) :
    for j in range(N) :
        if plate[i][j] != '_' :
            head = (i, j)
            break
    if head != (0, 0) :
        break

heart = (head[0]+1, head[1])
cnt_leftarm = 0
cnt_rightarm = 0
cnt_waist = 0
cnt_leftleg = 0
cnt_rightleg = 0


for i in range(heart[1]) : 
    if plate[heart[0]][i] != '_' :
        cnt_leftarm += 1
    

for i in range(heart[1]+1, N) :
    if plate[heart[0]][i] != '_' :
        cnt_rightarm += 1
        
for i in range(heart[0]+1, N) :
    if plate[i][heart[1]] != '_' :
        cnt_waist += 1
        
leg_start = heart[0] + cnt_waist + 1

for i in range(leg_start, N) :
    if plate[i][heart[1]-1] != '_' :
        cnt_leftleg += 1
    if plate[i][heart[1]+1] != '_' :
        cnt_rightleg += 1

print(heart[0]+1, end = ' ')
print(heart[1]+1)

print(cnt_leftarm, end =' ')
print(cnt_rightarm, end =' ')
print(cnt_waist, end =' ')
print(cnt_leftleg, end =' ')
print(cnt_rightleg, end =' ')