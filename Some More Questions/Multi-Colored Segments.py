t = int(input())
out = ""
 
for _ in range(t):
    n = int(input())
 
    segs = []
    for i in range(n):
        segs.append([int(x)-1 for x in input().split()])
        segs[-1].append(i)
 
    segs.sort()
 
    sg = []
    last = -1
    for x in segs:
        if x[-2] != last:
            sg.append([])
            last = x[-2]
 
        sg[-1].append(x)
 
    ans = [float("inf")]*n
 
    e = 0
    c = sg[0][0][-2]
    for x in sg[0]:
        ans[x[-1]] = max(0, sg[1][0][0] - x[1])
 
        e = max(e, x[1])
 
    e2 = 0
    c2 = sg[1][0][-2]
    for x in sg[1]:
        if len(sg) > 2:
           ans[x[-1]] = max(0, sg[2][0][0] - x[1])
 
        ans[x[-1]] = min(ans[x[-1]], max(0, x[0] - e))
 
        e2 = max(e2, x[1])
 
    for i in range(1, len(sg)):
        te = sg[i][0][1]
        for x in sg[i]:
            if c != x[-2]:
                ans[x[-1]] = max(0, x[0] - e)
            else:
                ans[x[-1]] = max(0, x[0] - e2)
 
            if i < len(sg)-1:
                ans[x[-1]] = min(ans[x[-1]], max(0, sg[i+1][0][0]-x[1]))
 
            te = max(te, x[1])
 
        if te > e:
            if sg[i][0][-2] == c:
                e = te
            else:
                e2 = e
                c2 = c
                e = te
                c = sg[i][0][-2]
 
        elif te > e2 and sg[i][0][-2] != c:
            e2 = te
            c2 = sg[i][0][-2]
 
    for x in ans:
        out += str(x) + " "
    out += "\n"
 
print(out)
