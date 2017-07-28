#include <bits/stdc++.h>
using namespace std;
int data[305][305], countData[305], isChoose[305];
int main()
{
    int n, m, result = INT_MAX, now, nowPos;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            scanf("%d", &data[i][j]);
    }
    for (int i = 1; i <= m; ++i)
        isChoose[i] = 1;

    do
    {
        now = 0;
        nowPos = 0;
        memset(countData, 0, sizeof(countData));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (isChoose[data[i][j]] == 1)
                {
                    ++countData[data[i][j]];
                    break;
                }
            }
        }
        for (int i = 1; i <= m; ++i)
        {
            if (now < countData[i])
            {
                now = countData[i];
                nowPos = i;
            }
        }
        if (now == 0)
        {
            break;
        }
        else
        {
            result = min(now, result);
            isChoose[nowPos] = 0;
        }
    }while(true);
    printf("%d\n", result);
    return 0;
}
