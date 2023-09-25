n = int(input())
steps = [list(map(int, input().split())) for i in range(n)]
tc = int(input())
for _ in range(tc):
    path = input()
    cur = path[0]
    ans = 0
    for i in range(1, len(path)):
        ans += steps[ord(cur)-65][ord(path[i])-65]
        cur = path[i]
    print(ans)
