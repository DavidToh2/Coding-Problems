n = int(input())
x = [0 for i in range(n)]
y = [0 for i in range(n)]

for i in range(n):
    x[i], y[i] = input().split()
    x[i] = int(x[i])
    y[i] = float(y[i])

m = int(input())

for j in range(m):
    L, R, l, X = input().split()
    L = int(L)
    R = int(R)
    l = float(l)
    X = float(X)

    [a, b, c, d, e, f] = [l, 0, l, 0, 0, 0]

    for k in range(L-1, R):
        a += x[k]*x[k]
        b += 2*x[k]
        c += 1
        d -= 2*x[k]*y[k]
        e -= 2*y[k]
        f += y[k]*y[k]
    
    if (b*b - 4*a*c != 0):
        K = 1.0 * (2*c*d - b*e) / (b*b - 4*a*c)
        B = 1.0 * (2*a*e - b*d) / (b*b - 4*a*c)

    print(K*X + B)