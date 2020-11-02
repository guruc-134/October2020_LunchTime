t=int(input())
for i in range(t):
    n=int(input())
    arr=[int(i) for i in input().split()]
    ans=0
    sum=0
    for ele in arr:
        ans |=ele
        sum+=ele
        ans |= sum
    print(ans)
