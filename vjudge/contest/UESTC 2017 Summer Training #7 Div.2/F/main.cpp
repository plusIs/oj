#include <bits/stdc++.h>
using namespace std;
char data[105][105];
bool tmp[105][105];

void update(int x, int y, int xPos, int yPos, bool first)
{
    if (first)
    {
        memset(tmp, 0, sizeof(tmp));
    }
    if (xPos >= 0 && xPos < x && yPos >= 0 && yPos < y && data[xPos][yPos] != 'X')
    {
        if (data[xPos][yPos] != 'D')
            ++data[xPos][yPos];
        else if (tmp[xPos][yPos] == false)
        {

            tmp[xPos][yPos] = true;
            update(x, y, xPos - 1, yPos, false);
            update(x, y, xPos + 1, yPos, false);
            update(x, y, xPos, yPos - 1, false);
            update(x, y, xPos, yPos + 1, false);
        }
    }
}

int main()
{
    int T, x, y, posNum, xPos, yPos;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &y, &x);
        getchar();
        for (int i = 0; i < x; ++i)
        {
            gets(data[i]);
        }
        scanf("%d", &posNum);
        for (int i = 0; i < posNum; ++i)
        {
            scanf("%d%d", &yPos, &xPos);
            update(x, y, xPos, yPos, true);
        }
        for (int i = 0; i < x; ++i)
        {
            puts(data[i]);
        }
    }
    return 0;
}