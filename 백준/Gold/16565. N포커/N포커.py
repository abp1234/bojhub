N=int(input())

lst=[[0]*53 for _ in range(53)]
lst[0][0]=lst[1][0]=lst[1][1]=1
for i in range(2, 53):
    lst[i][0]=lst[i][i]=1
    for j in range(1,i):
        lst[i][j] = lst[i-1][j] + lst[i-1][j-1]
result=0
cnt, line=1,1
while N>=4:
    result += line * lst[13][cnt] * lst[52-cnt*4][N-4]
    cnt+=1
    line=-line
    N-=4

print(result%10007)