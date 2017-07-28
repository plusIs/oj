#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T, n;
    double PI = acos(-1), result, R;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
    {
        scanf("%lf", &R);
        scanf("%d", &n);
        result = R * sin(PI / (double)n);
        result = result / ((double)1 + sin(PI / (double)n));
        printf("Case %d: %.7f\n",i, result);
    }
    return 0;
}
