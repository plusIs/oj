#include <bits/stdc++.h>
using namespace std;
int data[105][105];
int main()
{
    int n, m, xMin = 200, xMax = 0, yMin = 200, yMax = 0, maxLen, blackCount = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        getchar();
        for (int j = 1; j <= m; ++j)
        {
            if (getchar() == 'W')
                data[i][j] = 0;
            else
            {
                ++blackCount;
                if (i < xMin)
                    xMin = i;
                if (i > xMax)
                    xMax = i;
                if (j < yMin)
                    yMin = j;
                if (j > yMax)
                    yMax = j;
            }
        }
    }
    if (xMax == 0)
    {
        puts("1");
        return 0;
    }
    maxLen = max(xMax - xMin + 1, yMax - yMin + 1);
    if (maxLen > n || maxLen > m)
    {
        puts("-1");
        return 0;
    }
    printf("%d\n", maxLen * maxLen - blackCount);
    return 0;
}