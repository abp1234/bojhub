import sys, heapq
from dataclasses import dataclass
input = sys.stdin.readline
print = sys.stdout.write

@dataclass(order=True)
class Nd:
    cs: int
    x: int
    y: int
    ct: int

def cd(i, cu):

    nx = cu.x + dx[i]
    ny = cu.y + dy[i]
    if nx < 0 or ny < 0 or nx >= n or ny >= m: 
        return
    if bd[nx][ny] == -1: 
        return
    nc = cu.cs + bd[nx][ny]
    nt = cu.ct + 1
    if ds[nx][ny][nt % 3] <= nc: 
        return
    ds[nx][ny][nt % 3] = nc
    heapq.heappush(pq, Nd(nc, nx, ny, nt))

def dj(sx, sy, ex, ey):
    heapq.heappush(pq, Nd(0, sx, sy, 1))
    ds[sx][sy][1] = 0
    while pq:
        cu = heapq.heappop(pq)
        if ds[cu.x][cu.y][cu.ct % 3] < cu.cs:
            continue
        if cu.x == ex and cu.y == ey:
            return cu.ct

        if cu.ct % 3 == 0:
            for i in range(4):
                cd(i, cu)
        elif cu.ct % 3 == 1:
            for i in range(2):
                cd(i, cu)
        else:
            for i in range(2, 4):
                cd(i, cu)
    return -1

def main():
    global n, m, bd, dx, dy, ds, pq
    a = list(map(int, input().split()))
    n, m = a[0], a[1]
    b = list(map(int, input().split()))
    sx, sy, ex, ey = b[0]-1, b[1]-1, b[2]-1, b[3]-1 
    bd = [list(map(int, input().split())) for _ in range(n)] 
    
    dx = [-1, 1, 0, 0] 
    dy = [0, 0, -1, 1]
    

    ds = [[[float('inf')]*3 for _ in range(m)] for _ in range(n)]
    
    pq = []  
    
    rt = dj(sx, sy, ex, ey) 
    if rt == -1:
        print("-1")
    else:
        print(str(ds[ex][ey][rt % 3]))

if __name__ == '__main__':
    main()
