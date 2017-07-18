#include <bits/stdc++.h>
using namespace std;
set<int> data;
int oldP[105][105][2], newP[105][105][2];

int calc(int x, int y, int w, int h)
{
    int ret = 0;
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1;++j)
        {
            //if (x == 0 && y == 1)
                //printf("%d %d %d\n", oldP[(x + i) % h][(y + j) % w][0], (x + i + h) % h, (y + j + w) % w);
            ret += oldP[(x + i + h) % h][(y + j + w) % w][0];
        }
        //if (x == 0 && y == 1)
            //putchar('\n');
    }
    return ret;
}

void solve(int w, int h)
{
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            newP[i][j][0] = calc(i, j, w, h);
            newP[i][j][1] = oldP[i][j][1] + 1;
        }
    }
}
int main()
{
    int w, h, b;
    scanf("%d%d%d", &w, &h, &b);
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j <w; ++j)
            scanf("%d", &oldP[i][j][0]);
    }
    for (int i = 0; i < b; ++i)
    {
        if (i != 0)
            memcpy(oldP, newP, sizeof(newP));
        solve(w, h);
    }
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j <w; ++j)
        {
            data.insert(newP[i][j][0]);
            //printf("%d ", newP[i][j][0]);
        }
        //putchar('\n');
    }
    printf("%d\n", data.size());
    return 0;
}
