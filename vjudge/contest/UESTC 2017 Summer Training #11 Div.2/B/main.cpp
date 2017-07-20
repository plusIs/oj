#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> path;
bool data[10000];
struct Road
{
    int node;
    int from;
    int to;
};
vector<Road> g[1005];

void Euler(int u);

int calcNode(int road)
{
    int ret = road / 4;
    if (road % 4 != 0)
        ++ret;
    return ret;
}

bool cmp(Road &a, Road &b)
{
    return (a.from < b.from) && (a.to < b.to);
}

int main()
{
    freopen("courier.in", "r", stdin);
    freopen("courier.out", "w", stdout);
    
    int a, a1, b, b1, n;
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; ++i)
    {
        scanf("%d%d", &a, &b);
        a1 = calcNode(a);
        b1 = calcNode(b);
        g[a1].push_back({b1, a, b});
        g[b1].push_back({a1,  b, a});
    }
    sort(g[1].begin(), g[1].end(), cmp);
    Euler(1);
    for (int i = 1; i <= 4 * n; ++i)
    {
        if (data[i] == false)
        {
            puts("No");
            //printf("%d\n", i);
            break;
        }
        else if (i == 4 * n)
        {
            puts("Yes");
            for (int i = path.size() - 1; i >= 0; --i)
            {
                if (i != 0)
                    printf("%d %d ", path[i].first, path[i].second);
                else
                    printf("%d %d\n", path[i].first, path[i].second);
                
            }
        }
    }

    //path.push_back = s;
    return 0;
}

void Euler1(int u)
{
    printf("%d\n", u);
    int node;
    for (auto &each : g[u])
    {
        if (each.node != 0)
        {
            node = each.node;
            each.node = 0;
            for (auto &eachj : g[node])
            {
                if (eachj.node == node)
                    eachj.node = 0;
            }
            Euler(node);
            data[each.from] = true;
            data[each.to] = true;
            path.push_back(pair<int, int>(each.from, each.to));
        }
    }

}

void Euler(int u)
{
    //printf("%d\n", u);
    int node;
    for (int i = 0; i < g[u].size(); ++i)
    {
        if (g[u][i].node != 0)
        {
            node = g[u][i].node;
            g[u][i].node = 0;
            for (int j = 0; j < g[node].size(); ++j)
            {

                if (g[node][j].node == u && g[node][j].to == g[u][i].from)
                {
                    g[node][j].node = 0;
                }
            }
            //printf("u = %d node = %d from = %d to = %d\n", u, node, g[u][i].from, g[u][i].to);

            Euler(node);
            data[g[u][i].from] = true;
            data[g[u][i].to] = true;
            
            path.push_back(pair<int, int>(g[u][i].from, g[u][i].to));
        }
    }
}