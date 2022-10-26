for t in range(int(input())):
    n = int(input())
    b = []
    c = 0
    for i in range(n):
        a = list((map(int, input().split())))
        if 0 in a:
            c+=1
        for j in range(n):
            if a[j]==0 and j+1 not in b:
                b.append(j+1)
    b.sort()
    if c==n and b==[i+1 for i in range(n)]:
        print("YES")
    else:
        print("NO")
