A,B,C=map(int,input().split())
arr=[]
data_0=input().split()
data_1=input().split()
data_2=input().split()
for i in range(A+B+C):
    if i<A:
        arr.append([int(data_0[i]),0])
    elif i<A+B:
        arr.append([int(data_1[i-A]),1])
    else:
        arr.append([int(data_2[i-A-B]),2])
arr.sort()
check=[-21e7]*3
min_cnt=21e8
for i in range(A+B+C):
    if arr[i][1]==0:
        check[0]=arr[i][0]
        min_cnt=min(min_cnt,abs(check[0]-min(check[1],check[2])))
    elif arr[i][1]==1:
        check[1]=arr[i][0]
        min_cnt=min(min_cnt,abs(check[1]-min(check[0],check[2])))
    else:
        check[2]=arr[i][0]
        min_cnt=min(min_cnt,abs(check[2]-min(check[1],check[0])))
print(min_cnt)