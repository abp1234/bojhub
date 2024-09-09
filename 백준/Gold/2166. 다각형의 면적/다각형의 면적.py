import sys
import math
input = sys.stdin.readline

n=int(input())
lst=[list(map(int,input().split())) for _ in range(n)]

lst.append(lst[0])

p=0
m=0

for i in range(len(lst)-1):
    p+=(lst[i][0]*lst[i+1][1])
    m+=(lst[i][1]*lst[i+1][0])
a = math.fabs(0.5*(p-m))
print("%.1f"%a)