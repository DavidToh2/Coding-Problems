t = int(input())
for _ in range(t):
    n = int(input())
    A = list(map(int, input().split(' ')))
    B = list(map(int, input().split(' ')))
    at, bt = 0, 0
    pos, neg = 0, 0
    for i in range(n):
        k = A[i] + B[i]
        if k == 2:
            pos += 1
        elif k == -2:
                neg += 1
        else:
            if A[i] == 1:
                at += 1
            elif B[i] == 1:
                bt += 1
    xt, yt = min(at, bt), max(at, bt)
    if (yt - xt) > pos:
        xt += pos
        d = neg - (yt - xt)
        if (d < 0):
            yt -= neg
        else:
            yt = xt-d//2
            xt -= (d - d//2)
    else:
        c = pos - (yt - xt)
        xt = yt + c//2 - neg//2
        yt += (c - c//2) - (neg - neg//2)
    print(min(xt, yt))
