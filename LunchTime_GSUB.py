t=int(input())
for i in range(t):
    n,q=map(int,input().split())
    arr=list(map(int,input().split()))
    ans=1
    for i in range(1,n):
        ans+=(arr[i]!=arr[i-1])
    for i in range(q):
        x,y=map(int,input().split())
        x-=1
        if x!=0:
            ans-=(arr[x]!=arr[x-1])
            ans+=(y!=arr[x-1])
        if x!=n-1:
            ans-=(arr[x]!=arr[x+1])
            ans+=(y!=arr[x+1])     
        arr[x]=y
        print(ans)

