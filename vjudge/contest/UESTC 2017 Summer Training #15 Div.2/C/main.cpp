#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005], toSolve;
int s[100005], maxLen[100005], data[100005];

int findRoot(int node)
{
    int r = node;
    if (s[r] != r)
    {
        s[r] = findRoot(s[r]);
    }
    return s[r];
}

void insert(int r1, int r2)
{
    int r = findRoot(r1);
    s[r2] = r;
}

void update(int node, int newData, int from)
{
    for (auto each : g[node])
    {
        if (each != from)
            update(each, newData + 1, node);
    }
    maxLen[node] = newData;
}

int main()
{
    int c, l, a, b, ra, rb, a1, b1, result = 0;
    scanf("%d%d", &c, &l);
    for (int i = 0; i < c; ++i)
        s[i] = i;
    for (int i = 0; i < l; ++i)
    {
        scanf("%d%d", &a, &b);
        ra = findRoot(a);
        rb = findRoot(b);
        insert(ra, rb);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < c; ++i)
    {
        int ri = findRoot(i);
        if (data[ri] == 0)
            data[ri] = maxLen[i];
        else
            data[ri] = min(data[ri], maxLen[i]);
    }
    for (int i = 0; i < c; ++i)
    {
        printf("data[i]=%d i=%d %d\n", data[i], i, maxLen[i]);
        if (data[i] != 0)
            toSolve.push_back(data[i]);
    }
    sort(toSolve.begin(), toSolve.end(), greater<int>());
    for (size_t i = 1; i < toSolve.size(); ++i)
    {
        result = max(result, toSolve[0] + 1 + toSolve[i]);
    }
    printf("%d\n", result);
    return 0;
}
