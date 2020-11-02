#RS 
t=int(input())
for i in range(t):
    x=int(input())
    k = False
    for i in range(0, x):
        if ((i | x-i) + (i & x-i)):
            print(i, x-i)
            k = True
            break
    if (not k):
        print(-1)
