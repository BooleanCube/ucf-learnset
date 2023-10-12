t = int(input())

while t:
    t -= 1
    n, k = map(int, input().split())
    l = list(map(int, input().split()))
    while k:
        k -= 1
        l = [l[i]+l[i+1] for i in range(len(l)-1)]
    print(*l)
