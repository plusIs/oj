for n in range(3, 400):
    result = 0
    for i in range(1, n):
        for j in range(i, n - i):
            k = n - i - j
            if k < j:
                break
            if i * 2 < n and j * 2 < n and k * 2 < n:
                #print("%d %d %d" % (i, j, k))
                result += 1
                if i != j and j != k:
                    result += 1
    print(result)
