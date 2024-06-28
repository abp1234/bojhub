V,E=list(map(int,input().split()))
lst=[]
for _ in range(E):
    A,B,C=list(map(int,input().split()))
    lst.append([C,A-1,B-1])

lst.sort()
check=[]
for i in range(V):
    check.append(i)
def find_boss(A):
    if check[A]!=A:
        check[A]=find_boss(check[A])
    return check[A]
def union(A,B):
    A_boss=find_boss(A)
    B_boss=find_boss(B)
    if A_boss!=B_boss:
        check[B_boss]=A_boss
        return 1
    return 0
result=0
for i in range(E):
    C,A,B=lst[i]
    if union(A,B)==1:
        result+=C
print(result)