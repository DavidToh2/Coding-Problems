import math

q = int(input())
for i in range(q):
    p, r, y = map(float, input().split())
    A = (y+r+p)/2.0
    B = (y+r-p)/2.0
    # "(n, e, s, w) = (n, A-n, n-r, B-n)

    arr = [A/2, (A+r)/2, (B+r)/2, B/2, (A+B)/2, r/2]

    def gen(n):
        [a, b, c, d] = map(math.fabs, [n, A-n, n-r, B-n])
        return max([a, b, c, d])
    def gensol(n):
        print(f"{n} {A-n} {n-r} {B-n}")
    mingen = min([gen(x) for x in arr])
    t = [x for x in arr if gen(x)==mingen][0]
    gensol(t)

    
    
    
