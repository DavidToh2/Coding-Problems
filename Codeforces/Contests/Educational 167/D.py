n, m = list(map(int, input().split()))
A = list(map(int, input().split())) # cost of crafting
B = list(map(int, input().split())) # return of smelting
C = list(map(int, input().split())) # no. of ingots of each type you start with

D = [0]*1000000 # D[cost of one craft/smelt cycle] = min required threshold to craft
for i in range(n):
    t = A[i] - B[i]
    if D[t] != 0:
        if D[t] > A[i]:
            D[t] = A[i]
    else:
        D[t] = A[i]
Ds = [(c, t) for c, t in enumerate(D) if t > 0]
i = 0
while (i < len(Ds) - 1):
    (k1, v1), (k2, v2) = Ds[i], Ds[i+1]
    if v1 < v2:
        Ds.pop(i+1)
    else:
        i += 1
D = None

memo = [0]*1000000

res = 0
for j in range(m):
    c = C[j]
    
    # First weapon:
    k, v = Ds[0]
    if (c < v):
        True
    else:
        r = (c - v) // k + 1
        res += 2 * r
        c -= (r * k)
    
    # Second weapon onward: memoise
    c1, t1 = c, 0
    if (memo[c] != 0):
        t1 += memo[c]
    else:
        for k, v in Ds[1:]:
            # print(f"{k}, {v}, {j}, {c}")
            if (c < v):
                if (c < k):
                    break
                continue
            else:
                r = (c - v) // k + 1
                t1 += 2 * r
                c -= (r * k)
        memo[c1] = t1
    res += t1
print(res)