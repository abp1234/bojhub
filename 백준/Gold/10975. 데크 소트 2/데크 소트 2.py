N=int(input())
arr=[]
for i in range(N):
    temp=int(input())
    arr.append([temp,i])
arr.sort()
cnt=1
flag=0
now_num=arr[0][1]
for i in range(1,N):
    if arr[i][1]<now_num:
        if flag==0:
            flag=1
            now_num=arr[i][1]
        elif flag==1:
            now_num=arr[i][1]
        elif flag==2:
            now_num=arr[i][1]
            flag=0
            cnt+=1
    elif arr[i][1]>now_num:
        if flag==0:
            flag=2
            now_num=arr[i][1]
        elif flag==1:
            flag=2
            now_num=arr[i][1]
        elif flag==2:
            now_num=arr[i][1]

print(cnt)
