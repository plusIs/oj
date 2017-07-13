#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005
int maxLen[MAXN], a[MAXN];
int n;

void print(int index, int pre);
int main()
{
    //freopen("data.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);

        for (int i = n; i >= 1; --i)
        {
            maxLen[i] = 1;
            for (int j = n; j > i; --j)
            {
                if (a[j] > a[i] && maxLen[i] < maxLen[j] + 1)
                    maxLen[i] = maxLen[j] + 1;
            }
        }
        int maxIndex = 0;
        for (int i = 1; i <= n; ++i)
        {
            //printf("%d\n", maxLen[i]);
            if (maxLen[maxIndex] < maxLen[i])
                maxIndex = i;
        }
        printf("%d ", maxLen[maxIndex]);


        print(maxIndex, 0);
        putchar('\n');
    }
    return 0;
}

void print(int index, int pre)
{
    int next = 0;
    for (int i = index; i <= n ; ++i)
    {
        if (maxLen[i] == maxLen[index] &&  a[i] > pre && a[i] < a[index])
            index = i;
        if (next == 0 && maxLen[i] == maxLen[index] - 1)
            next = i;
    }
    printf("%d ", a[index]);
    if (maxLen[index] != 1)
        print(next, a[index]);
}