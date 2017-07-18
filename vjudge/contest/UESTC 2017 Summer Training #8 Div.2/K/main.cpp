#include <bits/stdc++.h>
using namespace std;
int x[1005], y[1005], r[1005], tmp[1005];
vector<int> g[1005];

void solve(int node, int color)
{
    if (tmp[node] == 0)
        tmp[node] = color;
    else if (tmp[node] != color)
    {
        puts("The input gear cannot move.");
        exit(0);
    }
    else
        return;
    for (auto each : g[node])
    {
        if (color == 1)
            solve(each, -1);
        else
            solve(each, 1);
    }
}

int main()
{
    int n, gcd;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d%d", &x[i], &y[i], &r[i]);
        for (int j = 0; j < i; ++j)
        {
            if ((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]) == (r[i] + r[j]) * (r[i] + r[j]))
            {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    solve(0, 1);
    if (tmp[n - 1] == 0)
        puts("The input gear is not connected to the output gear.");
    else
    {
        if (tmp[0] != tmp[n - 1])
            putchar('-');
        gcd = __gcd(r[n - 1], r[0]);
        printf("%d:%d\n", r[0] / gcd, r[n - 1] / gcd);
    }
    return 0;
}
