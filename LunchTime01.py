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
        
  # an alternative and preferred approach would be to just print 0 and the number itself as the answers
  # from the observations after considering some examples we can deduce that for any number the answer would be (0,number) 
