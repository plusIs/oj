#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q, g[7505];
int data[7505], pos[7505];
int main()
{
    int n = 1;
    while (scanf("%d", &data[n]) != EOF)
    {
        if (pos[data[n]] < n)
            pos[data[n]] = n;
        ++n;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (pos[i] == 0)
            q.push(i);
    }
    for (int i = 1; i < n; ++i)
    {
        g[data[i]].push(q.top());
        g[q.top()].push(data[i]);
        q.pop();
        if (pos[data[i]] == i)
            q.push(data[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        printf("%d:", i);
        while (g[i].empty() == false)
        {
            printf(" %d", g[i].top());
            g[i].pop();
        }
        putchar('\n');
    }
    return 0;
}
