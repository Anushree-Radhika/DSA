tt = int(input())
for tc in range(tt):
    n = int(input())
    h = list(map(int,input().split()))
    mx = -1e9
    mn = 1e9
    for x in h:
        mx = max(mx,x);
        mn = min(mn,x);
    
    print(mx-mn+1)
    
    