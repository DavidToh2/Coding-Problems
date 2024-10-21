def c2i(char):
    return "abcdefghijklmnopqrstuvwxyz".find(char)

def i2c(i):
    return "abcdefghijklmnopqrstuvwxyz"[i]

p = 10**9 + 7

rk, ck = map(int, input().split())
KK = []
for i in range(rk):
    K = input()
    KK.append([c2i(char) for char in K])

rh, ch = map(int, input().split())
HH = []
for i in range(rh):
    H = input()
    HH.append([c2i(char) for char in H])

hash1 = [[0] * (ch-ck+1) for i in range(rh)]
for i in range(rh):
    hash1[i][0] = sum([(2**k)*HH[i][k] for k in range(ck)])
    for j in range(ch-ck):
        hash1[i][j+1] = ((hash1[i][j] - HH[i][j]) // 2 + (2**(ck-1)) * HH[i][j+ck] ) % p

hash2 = [[0] * (ch-ck+1) for i in range(rh-rk+1)]
for i in range(ch-ck+1):
    hash2[0][i] = sum([(3**k)*hash1[k][i] for k in range(rk)])
    for j in range(rh-rk):
        hash2[j+1][i] = ((hash2[j][i] - hash1[j][i]) // 3 + (3**(rk-1)) * hash1[j+rk][i])%p

hashKK = 0
for i in range(rk):
    for j in range(ck):
        hashKK += (2**j) * (3**i) * KK[i][j]
        hashKK %= p
for i in range(rh-rk+1):
    for j in range(ch-ck+1):
        if hash2[i][j] == hashKK:
            hash2[i][j] = 1
        else:
            hash2[i][j] = 0


expand1 = [[0] * (ch-ck+1) for i in range(rh)]
expand2 = [[0] * ch for i in range(rh)]

for j in range(ch-ck+1):
    expand1[0][j] = hash2[0][j]
    for i in range(rh-1):
        expand1[i+1][j] = expand1[i][j]
        if i >= rk-1:
            expand1[i+1][j] -= hash2[i-rk+1][j]
        if i < rh-rk:
            expand1[i+1][j] += hash2[i+1][j]

for i in range(rh):
    expand2[i][0] = expand1[i][0]
    for j in range(ch-1):
        expand2[i][j+1] = expand2[i][j]
        if j >= ck-1:
            expand2[i][j+1] -= expand1[i][j-ck+1]
        if j < ch-ck:
            expand2[i][j+1] += expand1[i][j+1]

output = ""
for i in range(rh):
    for j in range(ch):
        if expand2[i][j] == 0:
            output += '.'
        else:
            output += i2c(HH[i][j])
    output += "\n"

print(output)