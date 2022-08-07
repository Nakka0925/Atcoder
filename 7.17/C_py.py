n, x, y = map(int, input().split())

if n == 1:
    print(0)
    exit()

a = [0] * (n+1)
b = [0] * (n+1)

a[1] = 0
b[1] = 1

for i in range(2, n+1):
    b[i] = a[i-1] + b[i-1] * y
    a[i] = a[i-1] + b[i] * x

print(a[n])