import math

q = int(input())
for i in range(q):
    p, r, y = map(int, input().split())
    A = (y+r+p)/2.0
    B = (y+r-p)/2.0
    # "(n, e, s, w) = (n, A-n, n-r, B-n)

    def gen(n):
        [a, b, c, d] = map(math.fabs, [n, A-n, n-r, B-n])
        return [a, b, c, d]
    def gensol(n):
        print(f"{n} {A-n} {n-r} {B-n}")

    t = [gen(x) for x in [A/2, (A+r)/2, (B+r)/2, B/2]]

    if (math.fabs(A/2 - (B+r)/2)) < (math.fabs((A+r)/2 - B/2)):
        print("look at (t[0], t[2])")
        if A/2 < (B+r)/2: 
            print("look at y_n and y_s")
            if t[0][1] < t[0][3]:
                print("the solution is at t[0]")
                gensol(A/2)
            elif t[2][3] < t[2][1]:
                print("the solution is at t[2]")
                gensol((B+r)/2)
            else:
                print("the solution is n = r")
                gensol(r/2)
        else: 
            print("look at y_e and y_w")
            if t[2][1] > t[2][3]:
                print("the solution is at t[2]")
                gensol((B+r)/2)
            elif t[0][3] > t[0][1]:
                print("the solution is at t[0]")
                gensol(A/2)
            else:
                print("the solution is n = math.fabs((A+B)/2)")
                gensol((A+B)/2)
    else:
        print("look at (t[1], t[3])")
        if (A+r)/2 > B/2: 
            print("look at y_n and y_s")
            if t[0][1] > t[0][3]:
                print("the solution is at t[1]")
                gensol((A+r)/2)
            elif t[3][3] > t[3][1]:
                print("the solution is at t[3]")
                gensol(B/2)
            else:
                print("the solution is n = r")
                gensol(r/2)
        else: 
            print("look at y_e and y_w")
            if t[2][1] < t[2][3]:
                print("the solution is at t[3]")
                gensol(B/2)
            elif t[0][3] < t[0][1]:
                print("the solution is at t[1]")
                gensol((A+r)/2)
            else:
                print("the solution is n = math.fabs((A+B)/2)")
                gensol((A+B)/2)
    print("\n")

    
    
