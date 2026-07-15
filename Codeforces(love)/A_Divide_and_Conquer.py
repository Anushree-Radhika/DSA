import math

tt = int(input())
for tc in range(tt):
    x,y = map(int,input().split())
    
    z = x/y
    m = math.floor(z)
    if(x%y == 0):
        print("YES")
    elif(x > y):
        print("NO")
    elif(m != 0 and ((x/m) == y)):
        print("YES")
    else:
        print("NO")