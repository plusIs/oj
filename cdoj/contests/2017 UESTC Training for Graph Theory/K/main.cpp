#include <bits/stdc++.h>
#define MAX_N 1050000

using namespace std;

//1050000
vector<pair<int, int>> g[MAX_N];
int dis[MAX_N], f[MAX_N];

priority_queue<pair<int, int>,
               vector<pair<int, int>>,
               greater<pair<int, int>>>
    pr_que;

void update(int v)
{
    for (int i = 0; i < (int)g[v].size(); ++i)
    {
        if (dis[g[v][i].second] > g[v][i].first + dis[v])
        {
            dis[g[v][i].second] = g[v][i].first + dis[v];
            pr_que.push(pair<int, int>(dis[g[v][i].second], g[v][i].second));
        }
    }
}

int main()
{
    //freopen("data.in", "r", stdin);
    for (int i = 1; i < MAX_N; ++i)
        dis[i] = INT_MAX;
    int n, m, end;
    char str1[25], str2[25];
    scanf("%d%d", &n, &m);
    end = (1 << n) - 1;
    for (int i = 0; i < m; ++i)
    {
        int a, b, w;
        scanf("%s%s%d", str1, str2, &w);
        a = b = 0;
        for (int j = 0; j < n; ++j)
        {
            if (str1[n - j - 1] == '1')
                a += (1 << j);
            if (str2[n - j - 1] == '1')
                b += (1 << j);
        }
        g[a].push_back(pair<int, int>(w, b));
    }
    pr_que.push(pair<int, int>(0, 0));
    while (pr_que.empty() == false)
    {
        pair<int, int> tmp = pr_que.top();
        pr_que.pop();
        if (f[tmp.second] == 0)
        {
            f[tmp.second] = 1;
            update(tmp.second);
        }
    }
    /*for (int i = 0; i <= end; ++i)
    {
        printf("%d\n",dis[i]);
    }*/
    if (dis[end] != INT_MAX)
    {
        printf("%d\n", dis[end]);
    }
    else
        printf("-1\n");
    return 0;
}