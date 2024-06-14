N=int(input())
arr=list(map(int,input().split()))
S=int(input())

idx=0
while S>0 and idx<N:
    big=arr[idx]
    target=idx
    i=idx+1
    while i<N and i-idx<=S:
        if big<arr[i]:
            big=arr[i]
            target=i
        i+=1
    temp=arr[target]
    if target>idx:
        arr[idx+1:target+1]=arr[idx:target]
        arr[idx]=temp
        S-=-idx+target
    idx+=1
print(*arr)