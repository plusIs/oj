#include <bits/stdc++.h>
using namespace std;
int data[100005];

int ngcd(int *a, int n)
{
    if (n == 1)
        return *a;
    return __gcd(a[n - 1], ngcd(a, n - 1));
}

int main()
{
    int n, k, allGcd;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &data[i]);
    sort(data, data + n);
    if (data[n - 1] < k)
    {
        puts("IMPOSSIBLE");
        return 0;
    }
    allGcd = ngcd(data, n);
    for (int i = n - 1; i >= 0; --i)
    {
        if ((data[i] - k) % allGcd == 0)
        {
            puts("POSSIBLE");
            return 0;
        }
    }
    puts("IMPOSSIBLE");

    return 0;
}
