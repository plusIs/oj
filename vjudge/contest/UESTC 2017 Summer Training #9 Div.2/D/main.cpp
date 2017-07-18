#include <bits/stdc++.h>
using namespace std;
vector<int> g[1005], f[1005];
int data[1005],    //深度
    sg[1005];      //sg
queue<int> q;

int dfs_sg(int node)
{
    if (sg[node] != -1)
        return sg[node];
    if (f[node].size() == 0)
    {
        sg[node] = 0;
        return sg[node];
    }
    int vis = 0;
    for (auto each : f[node])
    {
        if (each == -1)
            continue;
        if (dfs_sg(each) == 0)
        {
            vis = 1;
            break;
        }
        //vis.insert(dfs_sg(each, node));
        //vis[dfs_sg(each, node)] = true;
    }
    /*for (int i = 0;; ++i)
    {
        //if (vis[i] == 0)
        if (vis.find(i) == vis.end())
        {
            sg[node] = i;
            //delete vis;
            return sg[node];
        }
    }*/
    sg[node] = vis;
    return sg[node];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    memset(sg, -1, sizeof(sg));

    int n, m, a, b;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    q.push(1);
    data[1] = 1;
    while (q.empty() == false)
    {
        int front = q.front();
        q.pop();
        for (auto each : g[front])
        {
            if (data[each] == 0)
            {
                data[each] = data[front] + 1;
                q.push(each);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < g[i].size(); ++j)
        {
            if (data[g[i][j]] > data[i])
            {
                f[i].push_back(g[i][j]);
            }
        }
    }

    if (dfs_sg(1) == 0)
        puts("Nikolay");
    else
        puts("Vladimir");
    return 0;
}
