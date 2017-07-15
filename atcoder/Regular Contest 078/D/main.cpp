#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];
int data[100005];
vector<int> road;

set<int> tmp;

bool dfs(int n, int end, int from)
{
    //printf("%d\n", n);
    if (n == end)
        return true;
    for (auto each : g[n])
    {
        if (each != from && dfs(each, end, n) == true)
        {
            road.push_back(each);
            tmp.insert(each);
            return true;
        }
    }
    return false;
}

void calc(int n, int from, int first)
{
    if (tmp.find(n) != tmp.end() && n != first)
        return;
    ++data[first];
    for (auto each : g[n])
    {
        if (each != from)
        {
            calc(each, n, first);
        }
    }
}

int main()
{
    int n, a, b, black = 0;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, n, 0);
    road.push_back(1);
    tmp.insert(1);
    for (auto each : road)
    {
        calc(each, 0, each);
        
        //printf("%d\n", each);
        
    }
    //puts("end");
    //for (int i = 1; i <= n; ++i)
        //printf("%d\n", data[i]);
    for (int i = road.size()/2; i < road.size(); ++i)
    {
        black += data[road[i]];
        //printf("%d %d\n", data[road[i]], road[i]);
    }
    if (black > n - black)
        puts("Fennec");
    else
        puts("Snuke");
    return 0;
}
