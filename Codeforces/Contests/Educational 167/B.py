t = int(input())
for _ in range(t):
    a = input() # substring (must be contiguous)
    b = input() # subsequence
    x, y = len(a), len(b)
    minres = 1e9
    for i in range(y):
        if x + i > minres:
            break
        i1, j = i, 0
        while j < x and i1 < y:
            if a[j] == b[i1]:
                i1 += 1
            j += 1
        res = x + y - (i1 - i)
        if (res < minres):
            minres = res
    print(minres)