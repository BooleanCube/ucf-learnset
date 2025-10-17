from collections import deque


def encode(x):
    return "".join(map(str, x[0])) + "".join(map(str, x[1])) + "".join(map(str, x[2]))

def decode(s):
    cur = []
    for i in range(0, 9, 3):
        cur.append(list(map(int, s[i:i+3])))
    return cur

valid = lambda i, j: 0<=i<3 and 0<=j<3

def solve():
    a = [list(map(int, input().split())) for _ in range(3)]
    q = deque()
    q.append((0, encode(a)))
    vis = set()
    ans = 0
    dd = [1, -1, 0, 0]
    while q:
        pl, cur = q.popleft()
        if cur == "123456780":
            ans = pl
            break
        nxt = decode(cur)
        if cur in vis: continue
        vis.add(cur)
        i, j = [(i, j) for i in range(3) for j in range(3) if nxt[i][j] == 0][0]
        for k in range(4):
            di, dj = dd[k], dd[-k-1]
            if valid(i+di, j+dj):
                nxt[i][j], nxt[i+di][j+dj] = nxt[i+di][j+dj], nxt[i][j]
                enc = encode(nxt)
                if enc in vis:
                    nxt[i][j], nxt[i+di][j+dj] = nxt[i+di][j+dj], nxt[i][j]
                    continue
                q.append((pl + 1, enc))
                nxt[i][j], nxt[i+di][j+dj] = nxt[i+di][j+dj], nxt[i][j]

    print(ans)




n = int(input())
for _ in range(n): solve()