#include <bits/stdc++.h>
using namespace std;
int data[100005], data1[100005], data2[100005];
int main()
{
    int n, maxData = 0, minData = INT_MAX, result = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &data[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        maxData = max(maxData, data[i]);
        data1[i] = maxData;
    }
    for (int i = n; i >= 1; --i)
    {
        minData = min(minData, data[i]);
        data2[i] = minData;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (data[i] >= data1[i] && data[i] <= data2[i])
            ++result;
    }
    printf("%d\n", result);
    return 0;
}
