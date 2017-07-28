#include <bits/stdc++.h>
using namespace std;
int s[100005];

int findRoot(int node)
{
    int r = node;
    if (s[r] != r)
    {
        s[r] = findRoot(s[r]);
    }
    return s[r];
}

void insert(int r1, int r2)
{
    int r = findRoot(r1);
    s[r2] = r;
}

int main()
{
    int T, n, tmp;
    scanf("%d", &T);
    while (T--)
    {
        int result = 0;
        scanf("%d", &n);
        for (int i = 0; i <= n; ++i)
            s[i] = i;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &tmp);
            int rtmp, ri;
            rtmp = findRoot(tmp);
            ri = findRoot(i);
            if (ri == rtmp)
                ++result;
            else
                insert(tmp, i);
        }
        printf("%d\n", result);
    }

    return 0;
}
