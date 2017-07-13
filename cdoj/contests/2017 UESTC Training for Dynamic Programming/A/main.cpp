#include <bits/stdc++.h>
using namespace std;
#define MAXN 10

//int data[MAXN][MAXN];
int data[MAXN];

int main()
{
    //freopen("data.in", "r", stdin);
    int n, count = 0;
    scanf("%d", &n);
    int tmp;
    for (int i = 1; i <= n; ++i)
        data[i] = i;
    for (int i = 1; i <= n - 1; ++i)
    {
        for (int j = 1; j <= n / 2; ++j)
        {
            printf("%d %d ", data[j], data[n - j + 1]);
        }
        putchar('\n');
        tmp = data[2];
        for (int j = 2; j <= n; ++j)
            data[j] = data[j + 1];
        data[n] = tmp;
    }

    return 0;
}