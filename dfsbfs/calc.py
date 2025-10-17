from collections import deque

n = int(input())

while n:
    n -= 1
    a, b, c, t = map(int, input().split())
    q = deque()
    q.append((0, 0))
    vis = [0] * 1000000
    f = 0
    while q:
        cur, dep = q.popleft()
        if cur == t:
            f = 1
            print(dep)
            break
        if vis[cur]: continue
        vis[cur] = 1
        if not vis[(cur + a) % 1000000]: q.append(((cur + a) % 1000000, dep + 1))
        if not vis[(cur * b) % 1000000]: q.append(((cur * b) % 1000000, dep + 1))
        if not vis[(cur // c) % 1000000]: q.append(((cur // c) % 1000000, dep + 1))
    if not f: print(-1)