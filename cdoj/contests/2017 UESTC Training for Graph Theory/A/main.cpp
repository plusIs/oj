#include <bits/stdc++.h>
using namespace std;

int g[205][205], setData[205];
//priority_queue<int, vector<int>, greater<int>> pr_que;

struct Data
{
    int u, v, w;
    bool operator<(Data data) const
    {
        if (this->w < data.w)
            return true;
        else
            return false;
    }
} data[1005];

int find(int x)
{
    int r = setData[x];
    if (r != x)
        r = find(r);
    setData[x] = r;
    return r;
}

bool join(int a, int b)
{
    int ra, rb;
    ra = find(a);
    rb = find(b);
    if (rb != ra)
    {
        setData[rb] = ra;
        return true;
    }
    else
        return false;
}

int main()
{
    //freopen("data.in", "r", stdin);
    int n, m, u, v, w, ret = INT_MAX;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        g[u][v] = w;
        g[v][u] = w;
        data[i].u = u;
        data[i].v = v;
        data[i].w = w;
    }
    sort(data, data + m);
    for (int i = 0; i < m; ++i)
    {
        int ma, mi;
        ma = mi = data[i].w;
        for (int i = 0; i < 205; ++i)
            setData[i] = i;
        for (int j = i; j < m; ++j)
        {
            if (join(data[j].u, data[j].v))
            {
                ma = max(ma, data[j].w);
                mi = min(mi, data[j].w);
            }
            if (find(1) == find(n))
            {
                ret = min(ret, ma - mi);
            }
        }
        if (find(1) != find(n))
            break;
    }
    printf("%d\n", ret);
    return 0;
}