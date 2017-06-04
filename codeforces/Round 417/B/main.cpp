#include <bits/stdc++.h>
using namespace std;
int dp[15][5];//0 选择 1 左到右 2 右到左 3 左到左 4 右到右
int main()
{
    int n, m, l, r;
    char str[120];
    scanf("%d%d", &n, &m);
    for (int i = n - 1; i >= 0; --i)
    {
        l = 0;
        r = m + 1;
        scanf("%s", str);
        for (int j = 1; j < m; ++j)
        {
            if (str[j] == '1')
                l = j;
        }
        for (int j = m - 2; j >= 0; --j)
        {
            if (str[j] == '1')
                r = j;
        }
        dp[i][1] = m + 1;
        dp[i][2] = m + 1;
        dp[i][3] = 2 * r;
        dp[i][4] = (m - l + 1) * 2;
        printf("%d %d %d %d\n", dp[i][1], dp[i][2], dp[i][3], dp[i][4]);
        
    }
    return 0;
}