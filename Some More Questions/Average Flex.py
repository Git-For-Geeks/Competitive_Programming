# cook your dish here
from collections import Counter
for _ in range(int(input())):
  n = int(input())
  a = list(map(int, input().split( )))
  a.sort()
  d = list(Counter(a).values())

  ans = 0
  s = 0
  for i in d:
    s += i
    if s > (n - s):
      ans += i
  print(ans)
