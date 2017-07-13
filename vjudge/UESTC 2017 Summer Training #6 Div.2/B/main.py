a = int(input())
b = int(input())
c = int(input())
l = [a, b, c]
l.sort()
if l[0] + l[1] == l[2] or l[0] + l[0] == l[2] or l[1] + l[1] == l[2] or l[0] + l[0] == l[1]:
    print('YES')
else:
    print('NO')
