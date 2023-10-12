import math

tc = int(input())
while tc:
    tc -= 1
    n = int(input())
    ans = 0
    for _ in range(n):
        s, p = map(int, input().split())
        ans += s*math.ceil(p/4)
    print(ans)