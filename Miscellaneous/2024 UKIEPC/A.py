a = input()
b = input()

frequency_a = dict()
frequency_b = dict()

for char in "qwertyuiopasdfghjklzxcvbnm":
    frequency_a[char] = 0
    frequency_b[char] = 0

for char in a:
    frequency_a[char] += 1

for char in b:
    frequency_b[char] += 1

output = ""

for char in "qwertyuiopasdfghjklzxcvbnm":
    output += char * max(frequency_a[char], frequency_b[char])

print(output)