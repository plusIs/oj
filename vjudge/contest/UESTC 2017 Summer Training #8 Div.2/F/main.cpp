#include <bits/stdc++.h>
using namespace std;
int data1[100005];
int main()
{
    int n, result = INT_MAX;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &data1[i]);
    sort(data1, data1 + n);
    for (int i = 0; i < n / 2; ++i)
    {
        result = min(result, data1[i] + data1[n - i - 1]);
    }
    printf("%d\n", result);
    return 0;
}