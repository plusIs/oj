#include <bits/stdc++.h>
using namespace std;
vector<int> g[200005][2];
int data[200005];
queue<int> q;
int dfs(int node, int from)
{
    int ret = 0;
    for (auto each : g[node][0])
    {
        if (each != from)
            ret += dfs(each, node);
    }
    for (auto each : g[node][1])
    {
        if (each != from)
        {
            ret += dfs(each, node);
            ++ret;
        }
    }
    return ret;
}

void update(int node, int from)
{
    if (data[node] != -1)
        return;
    if (from < 0)
    {
        data[node] = data[-1 * from] - 1;
    }
    else
    {
        data[node] = data[from] + 1;
    }
    for (auto each : g[node][0])
    {
        update(each, node);
    }

    for (auto each : g[node][1])
    {
        update(each, -1 * node);
    }
}

int main()
{
    int n, a, b, result = INT_MAX;
    memset(data, -1, sizeof(data));
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        scanf("%d%d", &a, &b);
        g[a][0].push_back(b);
        g[b][1].push_back(a);
    }
    data[1] = dfs(1, 0);
    //printf("%d\n", data[1][1]);
    for (auto each : g[1][0])
    {
        update(each, 1);
    }

    for (auto each : g[1][1])
    {
        update(each, -1);
    }

    for (int i = 1; i <= n; ++i)
    {
        result = min(data[i], result);
    }
    printf("%d\n", result);
    for (int i = 1; i <= n; ++i)
    {
        if (data[i] == result)
            printf("%d ", i);
    }
    putchar('\n');
    return 0;
}