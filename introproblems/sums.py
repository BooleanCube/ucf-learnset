tc = int(input())

for tcn in range(1,1+tc):
    n = int(input())
    print(tcn, n, sum(i*((i+1)*(i+2)//2) for i in range(1, n+1)))
