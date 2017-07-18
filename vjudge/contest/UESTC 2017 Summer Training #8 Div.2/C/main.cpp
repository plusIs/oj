#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, maxSafe, minBreak, x;
    char str[100];
    scanf("%d%d", &n, &k);
    maxSafe = 1;
    minBreak = k;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%s", &x, str);
        if (strcmp(str, "BROKEN") == 0)
        {
            if (minBreak > x)
                minBreak = x;
        }
        else
        {
            if(maxSafe < x)
                maxSafe = x;
        }
        if (minBreak == INT_MAX)
            minBreak = k;
    }
    printf("%d %d\n", maxSafe + 1, minBreak - 1);
    return 0;
}
