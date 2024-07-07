from collections import OrderedDict

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

memo = {}
    
res = 0
for j in range(m):
    c, t = C[j], 0
    T, arr = [], []
    for i, (k, v) in enumerate(Ds):
        if (c, i) in memo.keys():
            t += memo[(c, i)]
            break
        if (c < v):
            if (c < k):
                break
            i+=1
            continue
        else:
            r = (c - v) // k + 1
            T.append(r)
            arr.append((c, i))
            c -= (r * k)
            i+=1
    l = len(T)
    for j in range(l-1, -1, -1):
        t += T[j]
        memo[arr[j]] = t
    res += 2 * t
    del T
    del arr
print(res)

