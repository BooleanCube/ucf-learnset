from bisect import bisect_left

ps = [2**i for i in range(1, 40)]
t = int(input())
for _ in range(t):
    n = int(input())
    if n == 1: print(1,1); continue
    idx = bisect_left(ps, n+2)
    print(idx, 2**idx-1)
