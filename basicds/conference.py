from queue import PriorityQueue
from math import ceil
import sys
input = sys.stdin.readline
print = lambda *args : sys.stdout.write(" ".join(map(str, args)) + "\n")
n, t = map(int, input().split())
lectures = list(map(lambda x:(x[0],int(x[1])), [input().split() for _ in range(n)]))
lo, hi = 1, 10**5+7
ans = []
while lo <= hi:
    ans = []
    r, time = ceil(lo+(hi-lo)/2), 0
    nv = PriorityQueue()
    for i in range(r): nv.put((0, i))
    for l in lectures:
        vac, room = nv.get(); nv.put((vac+l[1], room))
        time = max(time, vac+l[1])
        ans.append((l[0], room, vac))
    if time <= t: hi = r-1
    else: lo = r+1
ans.sort()
for name, idx, time in ans: print(name, idx, time)