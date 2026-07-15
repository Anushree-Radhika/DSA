tt = int(input())
for tc in range(tt):
    n = int(input())
    h = list(map(int,input().split()))
    ans = []
    
    for s in range(n):
        w1 = [0] * n
        w2 = [0] * n
        
        for i in range(1,n):
            w1[(s+i)%n] = max(w1[(s+i-1)%n], h[(s+i-1)%n])
            w2[(s+n-i)%n] = max(w2[(s+n-i+1)%n],h[(s+n-i)%n])
            
        w = [min(w1[i],w2[i]) for i in range(n)]
        
        ans.append(sum(w))
    print(*ans)
    
    