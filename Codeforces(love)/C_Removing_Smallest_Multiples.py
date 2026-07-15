tt = int(input())

for tc in tt:
    
    n = int(input())
    s = str(input())
    num = []
    for i in range(0,s.length()):
        if  s[i] == '0':
            
            num.append(i+1);