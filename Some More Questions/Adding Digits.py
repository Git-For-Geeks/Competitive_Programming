a,b,n=map(int,raw_input().split());a=a*10+9
if(a%b)<10:print str(a-a%b)+"0"*(n-1)
else:print-1
