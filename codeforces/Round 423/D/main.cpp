#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, result, mod;
    scanf("%d%d", &n, &k);
    result = (n - 1) / k * 2;
    if ((n - 1) % k != 0)
        ++result;
    printf("%d\n", result);
    for (int i = 0)
    return 0;
}