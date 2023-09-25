from statistics import median

tc = int(input())
for tcn in range(1,1+tc):
    n = int(input())
    l = [int(input().split()[1]) for _ in range(n)]
    print(f"Case #{tcn}:", max(l), min(l), str(round(median(l),1)).replace(".0", ""))
