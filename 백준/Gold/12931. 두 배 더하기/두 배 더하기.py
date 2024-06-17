N=int(input())
A=[0]*N
if N !=1:
    B=list(map(int,input().split()))
if N==1:
    B=[int(input())]
cnt=0
while 1:
    sm_cnt=0
    for i in range(N):
        if B[i]%2!=0:
            cnt+=1
            B[i]-=1
        B[i]/=2
        if B[i]==0:
            sm_cnt+=1
    if sm_cnt==N:
        break
    cnt+=1
    
print(cnt)

