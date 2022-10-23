for q in range(int(input())):
    n, x=map(int,input().split())
    s=list(map(int,input().split()))
    s.sort()
    if x in s:
        print("YES")
    elif max(s) <x:
        print("NO")
    elif min(s)>x:
        print("NO")
    else:
        print("YES")