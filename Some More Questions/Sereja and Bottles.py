l,q,r=[0]*1001,0,[]
for i in[*open(0)][1:]:
    b,a=map(int,i.split())
    l[a]+=1
    r+=[[a,b]]
for i in r:
    if l[i[1]]==0 or(i[0]==i[1]and l[i[1]]==1):q+=1
print(q)
