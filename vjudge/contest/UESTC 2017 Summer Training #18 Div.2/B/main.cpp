#include <bits/stdc++.h>
using namespace std;
int data[200][4];
int main()
{
    int Q, M, T;
    scanf("%d", &T);
    while (T--)
    {
        memset(data, 0, sizeof(data));
        scanf("%d%d", &Q, &M);
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < Q; ++j)
            {
                char a, b;
                getchar();
                a = getchar();
                getchar();
                b = getchar();
                if (b == 'T')
                    data[j][a - 'A'] = 1;
                else
                    data[j][a - 'A'] = -1;
            }
        }
        for (int i = 0; i < Q; ++i)
        {
            char ans = 0;
            for (int j = 0; j < 4; ++j)
            {
                if (data[i][j] == 1)
                {
                    ans = j + 'A';
                    break;
                }
                else if (data[i][j] == 0)
                {
                    if (ans == 0)
                        ans = j + 'A';
                    else
                        ans = '?';
                }
            }
            if (i != Q - 1)
                printf("%c ", ans);
            else
                printf("%c\n", ans);
        }
    }
    return 0;
}
