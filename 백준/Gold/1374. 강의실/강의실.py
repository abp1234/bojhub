import heapq
N=int(input())
inarr=[]
outarr=[]
for _ in range(N):
    temp=list(map(int,input().split()))
    heapq.heappush(inarr,[temp[1],temp[2]])
heapq.heappush(outarr,heapq.heappop(inarr)[1])

while inarr:
    if outarr[0]<=inarr[0][0]:
        heapq.heappop(outarr)
        heapq.heappush(outarr,inarr[0][1])
        heapq.heappop(inarr)
        
    else:
        heapq.heappush(outarr,inarr[0][1])
        heapq.heappop(inarr)
print(len(outarr))