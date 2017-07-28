P = int(input())
for p in range(0, P):
    s = input()
    (d, n) = s.split()
    d = int(d)
    n = int(n)
    result = 0
    for i in range(1, n//3):
        m = (n - i) // 2
        if (n - i) % 2 != 0:
            m += 1
        M = (n - 2 * i) // 2
        M += 1
        M = max(M, i + 1)
        if m - M > 0:
            result += 2 * (m - M)
        m = 0
        for j in range(M, m):
            k = n - i - j
            if k * 2 < n:
                result += 2
    m = n // 2
    if n % 2 == 1:
        m += 1
        if (m - 1) % 2 == 0:
            result += (m - 1) // 2
        else:
            result += (m - 1) // 2 + 1
        m = 0
    else:
        result += (m - 1) // 2
        m = 0

    print("%d %d" % (d, result))
