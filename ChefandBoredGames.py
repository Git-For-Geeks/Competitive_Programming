t=int(input())
while t!=0:
    n=int(input())
    s=0
    for i in range(1,n+1,2):
        s+=(n-i+1)**2
    print(s)
    t-=1