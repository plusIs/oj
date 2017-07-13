#include <bits/stdc++.h>
#define MAX 125
using namespace std;
long long a[MAX], b[MAX], n1[MAX], n2[MAX], v[MAX];

int main()
{
    a[0] = 1;
    for (int i = 1; i <= 120; ++i)
    {
        n2[i] = 120 / i;
        v[i] = i;
    }
    for (int i = 1; i <= 120; i++) //循环每个因子
    {
        memset(b, 0, sizeof(b));
        for (int j = n1[i]; j <= n2[i] && j * v[i] <= 120; j++) //循环每个因子的每一项
            for (int k = 0; k + j * v[i] <= 120; k++)           //循环a的每个项
                b[k + j * v[i]] += a[k];                      //把结果加到对应位
        memcpy(a, b, sizeof(b));                              //b赋值给a
    }
    long long num;

    while (scanf("%lld", &num) != EOF)
    {
        printf("%lld\n", a[num]);
    }
    return 0;
}
