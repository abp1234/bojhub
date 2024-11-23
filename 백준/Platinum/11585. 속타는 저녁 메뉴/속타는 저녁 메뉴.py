def pi_mk():
    p_sz = len(pat)
    pi =[0]*p_sz
    pre=0
    for suf in range(1,p_sz):
        while pre>0 and pat[suf] != pat[pre]:
            pre=pi[pre-1]
        if pat[suf]==pat[pre]:
            pre+=1
            pi[suf]=pre
    return pi

def kmp():
    p_sz =len(pat)
    pr_sz =len(par)
    pi = pi_mk()
    pat_idx=0
    global cnt
    for pr_idx in range(pr_sz):
        while pat_idx >0 and par[pr_idx] != pat[pat_idx]:
            pat_idx=pi[pat_idx-1]
        if par[pr_idx]==pat[pat_idx]:
            if pat_idx == p_sz-1:
                cnt+=1
                pat_idx=pi[pat_idx]
            else:
                pat_idx+=1

def gcd(a,b):
    while b !=0:
        a,b=b,a%b
    return a

n =int(input())
pat=''.join(input().split())
par=''.join(input().split())
par +=par[:-1]
cnt=0

kmp()

g=gcd(cnt,n)
print(f"{cnt//g}/{n//g}")
    
