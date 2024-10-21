n = int(input())
emoji = ""

for i in range(n):
    name = input()
    if name.find("rest") >= 0:
        emoji += "😎"
    elif name.find("leg") >= 0:
        emoji += "🦵"
    else:
        emoji += "💪"

emoji *= 31
print(f"1 {emoji[:7]}\n2 {emoji[7:14]}\n3 {emoji[14:21]}\n4 {emoji[21:28]}\n5 {emoji[28:31]}")