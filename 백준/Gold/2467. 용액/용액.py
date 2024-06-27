

N=int(input())
lst=list(map(int,input().split()))
min_cost=abs(lst[0]+lst[N-1])
min_lst=[lst[0],lst[N-1]]
zero_idx=0
start=0
end=N-1
while start<end:
    cur_sum=lst[start]+lst[end]

    if abs(cur_sum)<min_cost:
        min_cost=abs(cur_sum)
        min_lst = [lst[start], lst[end]]
    if cur_sum>0:
        end-=1
    elif cur_sum<0:
        start+=1
    else:
        break
print(*min_lst)