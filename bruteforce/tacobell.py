from itertools import combinations

tc = int(input())
for i in range(tc):
    n, m = map(int, input().split())
    l = [input() for _ in range(n)]
    print("\n".join(" ".join(sorted(comb)) for comb in sorted(combinations(l, m))))
    print()