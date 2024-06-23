N,L=map(int,input().split())
lst=[list(map(int,input().split())) for _ in range(N)]
lst.sort()
start=lst[0][0]
cnt=(lst[0][1]-lst[0][0])//L
if (lst[0][1]-lst[0][0])%L!=0:
    cnt+=1
    start+=((lst[0][1]-lst[0][0])//L+1)*L
else:
    start=lst[0][1]

for i in range(1,N):
    if start>=lst[i][0] and start<lst[i][1]:
        if (lst[i][1]-start)%L==0:
            cnt+=(lst[i][1]-start)//L
            start=lst[i][1]
        else:
            cnt+=(lst[i][1]-start)//L+1
            start+=((lst[i][1]-start)//L+1)*L
    elif start<lst[i][0]:
        if (lst[i][1]-lst[i][0])%L==0:
            cnt+=(lst[i][1]-lst[i][0])//L
            start=lst[i][1]
        else:
            cnt+=(lst[i][1]-lst[i][0])//L+1
            start=lst[i][0]+((lst[i][1]-lst[i][0])//L+1)*L
print(cnt)