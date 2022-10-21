def isPowerofTwo(n):
    return (n != 0) and ((n & (n - 1)) == 0)

n=int(input())
if isPowerofTwo(n):
    print(f"Number {n} is power of 2")
else:
    print(f"Number {n} is not power of 2")