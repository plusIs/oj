//#include <bits/stdc++.h>
#include <cstdio>
#include <queue>

using namespace std;

bool solve(int x, int y)
{
    if (x % 2 == 1 && y % 2 == 1)
        return false;
    else if (x <2 || y < 2)
        return false;
    if (y % 2 == 1)
        swap(x, y);
    if (x % 2 == 1)
    {
        if (x == 3)
            return true;
        else if (y % 6 != 0)
            return false;
        else
            return true;
    }
    else
    {
        
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int x, y, xMod, xDiv, yMod, yDiv;
        scanf("%d%d", &x, &y);
        if (solve(x, y))
            puts("Yes");

        else
            puts("No");
    }
    return 0;
}
