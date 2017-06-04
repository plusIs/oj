#include <bits/stdc++.h>
using namespace std;
int data[4][4];
int main()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            scanf("%d", &data[i][j]);
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (data[i][j] == 1)
            {
                if (data[i][3] == 1 || data[(i + 3 - j) % 4][3] == 1)
                {
                    printf("YES\n");
                    return 0;
                }
            }
        }
    }
    printf("NO\n");
    return 0;
}