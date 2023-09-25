import random
import math
from collections import defaultdict, Counter, deque, OrderedDict
from queue import PriorityQueue
from heapq import heapify, heappush, heappop
from functools import lru_cache, reduce
from bisect import bisect_left, bisect_right
from types import GeneratorType
import sys

MOD = 10**9+7
HMOD = 998244353
MAXN = 10**5+5
INF = 1e20
EPS = 1e-9

input = lambda : sys.stdin.readline().strip()
print = lambda *args : sys.stdout.write(" ".join(map(str, args)) + "\n")
write = lambda *args : sys.stdout.write(" ".join(map(str, args)))

getint = lambda : int(input())
getlist = lambda : list(map(int, input().split()))
getstr = lambda : list(input()) # mutable string

def solve():
    n = getint()
    l = [input() for _ in range(n)]
    names = []
    for name in l:
        f = [0]*26
        for c in name: f[ord(c)-ord("A")] -= 1
        names.append(tuple(f + [name]))
    names.sort()
    for name in names: print(name[-1])

testcases = 1
testcases = getint()
for c in range(1, testcases+1):
    print(f"Class #{c} ordering")
    solve()
    print()
