#include <bits/stdc++.h>
using namespace std;
char data[120][120];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m, result = 0;
    scanf("%d%d", &n, &m);
    getchar();
    for (int i = 1; i <= n; ++i)
    {
        gets(&data[i][1]);
        for (int j = 1; j <= m; ++j)
            data[i][j] -= '0';
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (data[i][j] != 0)
            {
                result += 2 + data[i][j] * 4;
                result -= min(data[i][j], data[i - 1][j]);
                result -= min(data[i][j], data[i + 1][j]);
                result -= min(data[i][j], data[i][j - 1]);
                result -= min(data[i][j], data[i][j + 1]);
            }
        }
    }
    printf("%d\n", result);
    return 0;
}
