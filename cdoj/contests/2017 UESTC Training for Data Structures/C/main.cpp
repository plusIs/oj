#include <bits/stdc++.h>
using namespace std;
int data[100005];
long long segTree[100005 * 8][5]; //值 x + 标记 len

int p;

void calc(long long *ret, long long *a, long long *b)
{
    ret[0] = (a[0] + b[0]) % p;
}

void tag(int node)
{
    segTree[node][3] = 1;
    segTree[node][0] = ((segTree[node][0] * segTree[node][1]) % p + segTree[node][2] * segTree[node][4] % p) % p;
    segTree[node * 2][1] *= segTree[node][1];
    segTree[node * 2][1] %= p;
    segTree[node * 2][2] *= segTree[node][1];
    segTree[node * 2][2] %= p;
    segTree[node * 2][2] += segTree[node][2];
    segTree[node * 2][2] %= p;
    segTree[node * 2 + 1][1] *= segTree[node][1];
    segTree[node * 2 + 1][1] %= p;
    segTree[node * 2 + 1][2] *= segTree[node][1];
    segTree[node * 2 + 1][2] %= p;
    segTree[node * 2 + 1][2] += segTree[node][2];
    segTree[node * 2 + 1][2] %= p;
    segTree[node][1] = 1;
    segTree[node][2] = 0;
}

void pushDown(int node, bool isLeaf)
{
    if (segTree[node][3] == 1 && isLeaf == false)
    {

        tag(node * 2);
        tag(node * 2 + 1);
    }
    segTree[node][3] = 0;
}

void build(int node, int l, int r)
{
    int mid = (l + r) / 2;
    segTree[node][0] = 0;
    segTree[node][1] = 1;
    segTree[node][2] = 0;
    segTree[node][3] = 0;
    segTree[node][4] = r - l + 1;
    if (l == r)
    {
        segTree[node][0] = data[l - 1];
        //printf("node = %d  %lld ret\n", node, segTree[node][0]);
        return;
    }
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    calc(segTree[node], segTree[node * 2], segTree[node * 2 + 1]);
    //printf("node = %d  %lld\n", node, segTree[node][0]);
}

void edit(int node, int l, int r, int el, int er, int k, int c)
{
    int mid = (l + r) / 2;
    if (el <= l && r <= er)
    {
        if (k == 1)
        {
            segTree[node][1] *= c;
            segTree[node][1] %= p;
            segTree[node][2] *= c;
            segTree[node][2] %= p;
        }
        else
        {
            segTree[node][2] += c;
            segTree[node][2] %= p;
        }

        tag(node);

        //printf("node = %d  %lld ret\n", node, segTree[node][0]);
        return;
    }
    pushDown(node, l == r);
    if (el <= mid)
        edit(node * 2, l, mid, el, er, k, c);
    if (mid < er)
        edit(node * 2 + 1, mid + 1, r, el, er, k, c);
    calc(segTree[node], segTree[node * 2], segTree[node * 2 + 1]);
    //printf("node = %d  %lld [%d %d]\n", node, segTree[node][0], l, r);
}

int query(int node, int l, int r, int ql, int qr)
{
    long long r1 = 0, r2 = 0;
    int mid = (l + r) / 2;
    if (ql <= l && r <= qr)
    {
        //printf("query node = %d  %lld  [%d %d] ret\n", node, segTree[node][0], l, r);
        return segTree[node][0];
    }
    pushDown(node, l == r);
    if (ql <= mid)
        r1 = query(node * 2, l, mid, ql, qr);
    if (mid < qr)
        r2 = query(node * 2 + 1, mid + 1, r, ql, qr);
    //printf("query node = %d  %lld\n", node, (r1 + r2) % p);
    return (r1 + r2) % p;
}

int main()
{
    //freopen("data.in", "r", stdin);
    int n, m, k, l, r, c;
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; ++i)
        scanf("%d", &data[i]);
    build(1, 1, n);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &k, &l, &r);
        if (k != 3)
        {
            scanf("%d", &c);
            edit(1, 1, n, l, r, k, c);
        }
        else
            printf("%d\n", query(1, 1, n, l, r));
    }
    return 0;
}