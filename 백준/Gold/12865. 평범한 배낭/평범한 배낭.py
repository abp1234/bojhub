N,K=map(int,input().split())
lst=[list(map(int,input().split())) for _ in range(N)]

check=[[0]*(K+1) for _ in range(N)]
for i in range(K+1):
    if lst[0][0]<=i:
        check[0][i]=lst[0][1]
for i in range(1,N):
    for j in range(K+1):
        if lst[i][0]<=j:
            if check[i-1][j-lst[i][0]]+lst[i][1]>check[i-1][j]:
                check[i][j]=check[i-1][j-lst[i][0]]+lst[i][1]
            else:
                check[i][j]=check[i-1][j]
        else:
            check[i][j]=check[i-1][j]
print(check[N-1][K])