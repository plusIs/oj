#include <bits/stdc++.h>
using namespace std;
int data[50005], g[50005];

int find(int x)
{
    int r = data[x];
    if (r != x)
        r = find(data[x]);
    g[x] = !(g[data[x]] ^ g[x]);
    data[x] = r;
    return r;
}

bool join(int a, int b)
{
    int ra, rb;
    ra = find(a);
    rb = find(b);
    if (ra == rb)
    {
        if (g[b] == g[a])
            return true;
        return false;
    }

    data[rb] = ra;
    g[rb] = !(g[b] ^ g[a]);
    return true;
}

bool diff(int a, int b)
{
    int ra, rb;
    ra = find(a);
    rb = find(b);
    if (ra == rb)
    {
        if (g[b] != g[a])
            return true;
        return false;
    }
    data[rb] = ra;
    g[rb] = g[b] ^ g[a];
    return true;
}

int main()
{
    //freopen("data1.in", "r", stdin);
    int n, m, a, b, t;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++i)
    {
        data[i] = i;
        g[i] = 1;
    }
    for (int i = 0; i < m; ++i)
    {
        bool ret;
        scanf("%d%d%d", &t, &a, &b);
        if (a > n|| b > n)
            ret = false;
        else if (t == 1)
            ret = join(a, b);
        else if (t == 2)
            ret = diff(a, b);
        if (ret == false)
            printf("%d ", i + 1);
    }
    printf("\n");
    return 0;
}