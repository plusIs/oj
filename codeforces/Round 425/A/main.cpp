#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main()
{
    ull n, k, result;
    scanf("%lld%lld", &n, &k);
    result = n % (k * 2ll);
    if (result <k)
        puts("NO");
    else
        puts("YES");
    return 0;
}