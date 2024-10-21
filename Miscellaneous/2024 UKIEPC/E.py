n = int(input())
h = input().split()

for i in range(n):
    h[i] = int(h[i])
h.append(10000000)
c = [i*i for i in range(n+1)]

for i in range(1,n+1):
    for j in range(i-1,-1,-1):
        if (i-j-1)*(i-j-1) >= c[i]:
            break
        if h[j] <= h[i]:
            c[i] = min(c[i], c[j] + (i-j-1)*(i-j-1))

print(c[n])