tt = int(input())
for tc in range(tt):
    n = int(input())
    if n == 10:
        print(-1)
    elif n % 12 == 10:
        print(22, n - 22)
    else:
        print(n % 12, n - (n % 12))
