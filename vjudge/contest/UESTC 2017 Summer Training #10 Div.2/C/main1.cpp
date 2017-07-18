#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> g[100005][2];
int d[100005], f[100005], result = 1, data[100005];

struct cmp1
{
    bool operator()(int x, int y)
    {
        return d[x] > d[y]; //小的优先级高
    }
};

priority_queue<int, vector<int>, cmp1> q;

void dfs(int node)
{
    ++data[node];
    //printf("%d\n", node);
    if (d[node] == 0)
        return;
    for (auto each : g[node][1])
    {
        //printf("%d %d %d %d %d\n", d[each.first], each.second, d[node], node, each.first);
        if (d[each.first] + each.second == d[node])
        {
            dfs(each.first);
        }
    }
}

int main()
{
    int v, e, a, b, w, s, t;
    scanf("%d%d", &v, &e);
    for (int i = 0; i < e; ++i)
    {
        scanf("%d%d%d", &a, &b, &w);
        g[a][0].push_back(pair<int, int>(b, w));
        g[b][1].push_back(pair<int, int>(a, w));
    }
    scanf("%d%d", &s, &t);
    for (int i = 0; i < v; ++i)
        d[i] = INT_MAX;
    data[s] = 1;
    d[s] = 0;
    q.push(s);
    while (q.empty() == false)
    {
        int node = q.top();
        q.pop();
        //printf("node=%d data[node]=%d\n", node, data[node]);

        if (f[node] == 1)
        {
            continue;
            //break;
        }
        f[node] = 1;
        //printf("%d\n", node);
        for (auto each : g[node][0])
        {
            //rintf("each.first=%d,d[each.first]=%d, d[node] + each.second=%d\n", each.first, d[each.first], d[node] + each.second);

            if (d[each.first] > d[node] + each.second)
            {
                d[each.first] = d[node] + each.second;
                data[each.first] = data[node];
                q.push(each.first);
            }
            else if (d[each.first] == d[node] + each.second)
                data[each.first] += data[node];
        }
    }
    if (d[s] == INT_MAX)
        data[t] = 0;
    //else
    //dfs(t);
    printf("%d\n", data[t]);
    //for (int i = 0; i < v; ++i)
    //printf("%d ", d[i]);
    //putchar('\n');
    //for (int i = 0; i < v; ++i)
    //printf("%d ", f[i]);
    return 0;
}
