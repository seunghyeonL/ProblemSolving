import sys


N, M = map(int, sys.stdin.readline().rstrip().split())

I_asc = [[]for i in range(N)]

for i in range(N) :
    line_map = map(int, sys.stdin.readline().rstrip().split())
    line = list(line_map)
    for j in range(M) :
        I = 2126*line[3*j] + 7152*line[3*j+1] + 722*line[3*j+2]
        if I <510000 :
            I_asc[i].append(chr(35))
        elif I <1020000 :
            I_asc[i].append(chr(111))
        elif I <1530000 :
            I_asc[i].append(chr(43))
        elif I <2040000 :
            I_asc[i].append(chr(45))
        else :
            I_asc[i].append(chr(46))

for i in range(N) :
    print("".join(I_asc[i]))