s = input()
zero = 0
one = 0
for ch in s:
    if ch == '0':
        zero += 1
    else:
        one += 1
print(min(zero, one))