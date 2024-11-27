import sys
from collections import deque

input = sys.stdin.readline
print = sys.stdout.write

dr=[1,-1,0,0]
dc=[0,0,1,-1]

def gv(m,r,c,cl,v):
    dist = float('inf')
    for a in range(r+1, len(m)):
        if m[a][c]=='x':
            if v[a][c]==cl:
                return float('inf')
            else:
                dist = min(dist, a - r - 1)
                break
    return min(dist, len(m) - r - 1)

def ck(m,v):
    cnt=1
    v[:]=[[0]*len(m[0]) for _ in range(len(m))]
    for i in range(len(m)):
        for j in range(len(m[0])):
            if m[i][j]=='x' and v[i][j]==0:
                ic =False
                cl=[]
                cl.append((i,j))
                v[i][j]=cnt
                q=deque([(i,j)])
                while q:
                    rr, cc = q.popleft()
                    for k in range(4):
                        nr, nc = rr+dr[k],cc+dc[k]
                        if nr==len(m)-1:
                            ic=True
                        if nr<0 or nc<0 or nr >=len(m) or nc >=len(m[0]):
                            continue
                        if v[nr][nc]!=0 or m[nr][nc]=='.':
                            continue
                        v[nr][nc]=cnt
                        cl.append((nr,nc))
                        q.append((nr,nc))
                if not ic:
                    ml=float('inf')
                    for rr, cc in cl:
                        ml = min(ml, gv(m,rr,cc,cnt,v))
                    for a, b in sorted(cl, reverse=True):
                        m[a + ml][b] = m[a][b]
                        m[a][b] = '.'
                    return
                cnt+=1

r, c = map(int,input().split())
mp = [list(input().strip()) for _ in range(r)]
n=int(input().strip())
sticks = list(map(int,input().strip().split()))
v=[[0]*c for _ in range(r)]

for a in range(n):
    t = sticks[a]
    if a%2==0:
        for i in range(c):
            if mp[r-t][i]=='x':
                mp[r-t][i]='.'
                break
    else:
        for i in range(c-1,-1,-1):
            if mp[r-t][i]=='x':
                mp[r-t][i]='.'
                break
    ck(mp,v)

for row in mp:
    print("".join(row)+"\n")