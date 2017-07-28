#include <bits/stdc++.h>
using namespace std;
int data[10], data1[10];

int getResult(int n)
{
    int result = 1;
    for (int i = 1; i <= n; ++i)
        result *= i;
    return result;
}

int main()
{
    bool tmp = true;
    int n, count = 0, sum;
    scanf("%d", &n);
    for (int i = 0; i < 10; ++i)
    {
        data[i] = i;
        data1[i] = i;
    }
    sum = getResult(n);
    printf("%d\n", sum);
    while (count < sum)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (i != n)
                printf("%d ", data1[i]);
            else
                printf("%d\n", data1[i]);
        }
        if ((count + 1) % (2 * n) == 0 && n >= 4)
        {
            puts("fuck!");
            for (int i = 3; i + 1 <= n; i += 2)
            {
                swap(data1[i], data1[i + 1]);
            }
        }
        else if (tmp)
        {
            for (int i = 1; i + 1 <= n; i += 2)
            {
                swap(data1[i], data1[i + 1]);
            }
        }
        else
        {
            for (int i = 2; i + 1 <= n; i += 2)
            {
                swap(data1[i], data1[i + 1]);
            }
        }
        tmp = !tmp;
        ++count;
    }
    return 0;
}