N=int(input())

lst=[list(map(int,input().split())) for _ in range(N)]
ans=I=2e8
for i in range(3):
    dp=[[I,I,I] for _ in range(N)]
    dp[0][i]=lst[0][i]
    for j in range(1,N):
        dp[j][0]=lst[j][0]+min(dp[j-1][1],dp[j-1][2])
        dp[j][1]=lst[j][1]+min(dp[j-1][0],dp[j-1][2])
        dp[j][2]=lst[j][2]+min(dp[j-1][0],dp[j-1][1])
    for k in range(3):
        if i !=k:
            ans=min(ans,dp[-1][k])

print(ans)