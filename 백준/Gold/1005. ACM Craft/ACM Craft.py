from collections import deque
T=int(input())
while T:
    T-=1
    N,K=map(int,input().split())
    D=list(map(int,input().split()))
    lst=[[] for _ in range(N+1)]
    sorting=[0]*(N+1)
    for _ in range(K):
        temp=list(map(int,input().split()))
        lst[temp[0]].append(temp[1])
        sorting[temp[1]]+=1
    craft=deque()
    for i in range(1,N+1):
        if sorting[i]==0:
            craft.append(i)
    W=int(input())
    time=0
    next_craft=deque()
    while D[W-1]!=0:
        time+=1
        L=len(craft)
        for _ in range(L):
            idx=craft.popleft()
            D[idx-1]-=1
            if D[idx-1]!=0:
                craft.append(idx)
            elif D[idx-1]==0:
                next_craft.append(idx)
        L=len(next_craft)
        for _ in range(L):
            j=next_craft.popleft()
            for i in lst[j]:
                sorting[i]-=1
                if sorting[i]==0:
                    craft.append(i)


    print(time)