import sys

n = sys.stdin.readline().rstrip()
input_str = map(int, sys.stdin.readline().rstrip())
input_lst = list(input_str)

print(sum(input_lst))