#include <bits/stdc++.h>
using namespace std;
long long data1[200005], data2[200005], data[200005];
int main()
{
    int n;
    long long minNum = (long long)INT_MAX * 10000000;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &data[i]);
        if (i > 0)
            data1[i] = data[i] + data1[i - 1];
        else
            data1[i] = data[i];
        //printf("%lld ", data1[i]);
    }
    //putchar('\n');
    for (int i = n - 1; i >= 0; --i)
    {
        if (i < n - 1)
            data2[i] = data2[i + 1] + data[i];
        else
            data2[i] = data[i];
            
    }
    for (int i = 0; i < n - 1; ++i)
    {
        //printf("%lld ", data2[i]);
        if (abs(data1[i] - data2[i + 1]) < minNum)
            minNum = abs(data1[i] - data2[i + 1]);

    }
    printf("%lld\n", minNum);
    return 0;
}
