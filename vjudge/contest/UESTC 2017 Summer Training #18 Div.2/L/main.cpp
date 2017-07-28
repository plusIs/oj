#include <bits/stdc++.h>
using namespace std;

bool isWin[2000];

int data[2000];

int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        memset(data, 1, sizeof(data));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &data[i]);
            isWin[i] = false;
        }
    }
    return 0;
}
