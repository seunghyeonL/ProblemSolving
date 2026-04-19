import sys
from typing import List


N : int = int(sys.stdin.readline().rstrip())

mod : List[List[int]] = [[1], [0, 2], [3, 7], [4, 6], [5]]
    
for i in range(5) :
    if N%8 in mod[i] :
        print(i+1)
