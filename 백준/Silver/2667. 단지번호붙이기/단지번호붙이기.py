from collections import deque
N=int(input())
arr=[list(map(int,input())) for _ in range(N)]
diry=[0,0,-1,1]
dirx=[-1,1,0,0]
q=deque()
result=[]
for i in range(N):
    for j in range(N):
        if arr[i][j]==1:
            cnt=1
            arr[i][j]=0
            q.append(i*100+j)
            while q:
                idx=q.popleft()
                for l in range(4):
                    dy=diry[l]+idx//100
                    dx=dirx[l]+idx%100
                    if dy<0 or dx<0 or dy>=N or dx>=N:continue
                    if arr[dy][dx]==1:
                        arr[dy][dx]=0
                        q.append(dy*100+dx)
                        cnt+=1
            result.append(cnt)
print(len(result))
# print('\n')
result.sort()
for i in range(len(result)):
    print(result[i])
    # print('\n')