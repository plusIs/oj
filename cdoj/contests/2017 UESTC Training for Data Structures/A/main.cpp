#include <bits/stdc++.h>
using namespace std;
#define maxn 50005
pair<int, int> segTree[maxn * 4];
int data[maxn];

pair<int, int> calc(pair<int, int> &a, pair<int, int> &b)
{
    pair<int, int> ret;
    if (a == pair<int, int>(0, 0))
        return b;
    if (b == pair<int, int>(0, 0))
        return a;
    ret.first = max(a.first, b.first);
    ret.second = min(a.second, b.second);
    return ret;
}

void build(int node, int l, int r)
{
    int m = (l + r) / 2;
    if (l == r)
    {
        segTree[node].first = data[l];
        segTree[node].second = data[l];
        return;
    }
    build(2 * node, l, m);
    build(2 * node + 1, m + 1, r);
    segTree[node] = calc(segTree[node * 2], segTree[node * 2 + 1]);
}

pair<int, int> query(int node, int l, int r, int ql, int qr)
{
    pair<int, int> r1(0, 0), r2(0, 0);
    int m = (l + r) / 2;
    if (ql <= l && r <= qr)
    {
        return segTree[node];
    }
    if (ql <= m)
    {
        r1 = query(node * 2, l, m, ql, qr);
    }
    if (qr > m)
    {
        r2 = query(node * 2 + 1, m + 1, r, ql, qr);
    }
    return calc(r1, r2);
}

int main()
{
    int n, q, a, b;
    pair<int, int> ret;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &data[i]);
    build(1, 1, n);
    for (int i = 0; i < q; ++i)
    {
        scanf("%d%d", &a, &b);
        ret = query(1, 1, n, a, b);
        printf("%d\n", ret.first - ret.second);
    }
    return 0;
}