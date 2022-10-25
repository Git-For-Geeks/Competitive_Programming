# cook your dish here
N,K=map(int,input().split())
A=list(map(int,input().split()))

if K==0:
    print(*A)
elif K%2==1:
    m=max(A)
    for i in range(len(A)):
        A[i]=m-A[i]
    print(*A)
else:
    m=max(A)
    for i in range(len(A)):
        A[i]=m-A[i]
    m=max(A)
    for i in range(len(A)):
        A[i]=m-A[i]
    print(*A)