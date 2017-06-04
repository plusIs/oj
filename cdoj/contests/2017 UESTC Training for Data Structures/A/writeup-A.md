

# A题

恩，就是个线段树

建树的话 模板应该是

```c++
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
```

核心思路就是二分， 直到 $l == r$ ，接着回溯时更新节点值

查询模板为

```c++
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
```

如果当前区间被查询区间包含，直接返回节点值

如果查询区间的左端在中点左边，查询左半部分

查询区间在中点右边，查询右半部分

以上