#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int data[100005];
vector<int> segTree[100005 * 4];
//0 1 左 右 lazy len

vector<int> update(vector<int> &r1, vector<int> &r2)
{
    int tmp = 0; //连接处相同时连接处的长度
    vector<int> ret(6, 0);
    if (r1 == ret) //为0时
        return r2;
    else if (r2 == ret)
        return r1;
    if (r1[3] * r2[2] > 0) //r1的右边与r2左边相同时
        tmp = r1[3] + r2[2];

    ret[2] = r1[2]; //更新左边
    ret[3] = r2[3]; //更新右边
    if (tmp != 0)
    {
        if (abs(r1[2]) == r1[5]) //r1颜色完全相同且连接处相同
            ret[2] = tmp;
        if (abs(r2[3]) == r2[5]) ///r2颜色完全相同且连接处相同
            ret[3] = tmp;
    }
    ret[0] = min(tmp, min(r1[0], r2[0]));//0的数量
    ret[1] = max(tmp, max(r1[1], r2[1]));//1的数量
    ret[5] = r1[5] + r2[5];//更新长度
    return ret;
}

void build(int node, int l, int r)
{
    int mid = (l + r) / 2;
    segTree[node].resize(6, 0);
    segTree[node][5] = r - l + 1;
    if (l == r)
    {
        if (data[l - 1] == 0)
        {
            segTree[node][0] = -1;
            segTree[node][2] = -1;
            segTree[node][3] = -1;
        }
        else
        {
            segTree[node][1] = 1;
            segTree[node][2] = 1;
            segTree[node][3] = 1;
        }
        //printf("%d [%d %d] [%d %d] ret\n", node, segTree[node][0], segTree[node][1], segTree[node][2], segTree[node][3]);
        return;
    }
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    segTree[node] = update(segTree[node * 2], segTree[node * 2 + 1]);
    //printf("%d [%d %d] [%d %d]\n", node, segTree[node][0], segTree[node][1], segTree[node][2], segTree[node][3]);
}

void tag(int node)
{
    for (int i = 0; i < 4; ++i)
        segTree[node][i] = -segTree[node][i];
    swap(segTree[node][0], segTree[node][1]);
    segTree[node][4] ^= 1;
}

void update_lazy(int node)
{
    segTree[node][4] = 0;

    if (segTree[node][5] != 1)
    {
        tag(node * 2);
        tag(node * 2 + 1);
    }
}

void edit(int node, int l, int r, int el, int er)
{
    int mid = (l + r) / 2;
    if (el <= l && r <= er)
    {
        tag(node);
        //printf("%d [%d %d] [%d %d] %d ret\n", node, segTree[node][0], segTree[node][1], segTree[node][2], segTree[node][3], segTree[node][5]);
        return;
    }
    if (segTree[node][4] == 1)
        update_lazy(node);

    if (el <= mid)
    {
        edit(node * 2, l, mid, el, er);
    }
    if (mid < er)
    {
        edit(node * 2 + 1, mid + 1, r, el, er);
    }
    segTree[node] = update(segTree[node * 2], segTree[node * 2 + 1]);
    //printf("r1 = %d [%d %d] [%d %d] %d\n", node, segTree[node * 2][0], segTree[node * 2][1], segTree[node * 2][2], segTree[node * 2][3], segTree[node * 2][5]);
    //printf("r2 = %d [%d %d] [%d %d] %d\n", node, segTree[node * 2 + 1][0], segTree[node * 2 + 1][1], segTree[node * 2 + 1][2], segTree[node * 2 + 1][3], segTree[node * 2 + 1][5]);
    //printf("%d [%d %d] [%d %d]\n", node, segTree[node][0], segTree[node][1], segTree[node][2], segTree[node][3]);
}

vector<int> query(int node, int l, int r, int ql, int qr)
{
    vector<int> r1(6, 0), r2(6, 0);
    int mid = (l + r) / 2;


    if (ql <= l && r <= qr)
    { 
        //printf("%d [%d %d] [%d %d] ret\n", node, segTree[node][0], segTree[node][1], segTree[node][2], segTree[node][3]);
        return segTree[node];
    }
    if (segTree[node][4] == 1)
        update_lazy(node);
    if (ql <= mid)
        r1 = query(node * 2, l, mid, ql, qr);
    if (mid < qr)
        r2 = query(node * 2 + 1, mid + 1, r, ql, qr);
    //printf("r1 = %d [%d %d] [%d %d]\n", node, r1[0], r1[1], r1[2], r1[3]);
    //printf("r2 = %d [%d %d] [%d %d]\n", node, r2[0], r2[1], r2[2], r2[3]);
    //printf("ret = %d [%d %d] [%d %d]\n", node, ret[0], ret[1], ret[2], ret[3]);
    return update(r1, r2);
}

int main()
{
    //freopen("data0.in", "r", stdin);
    int N, M, k, l, r;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &data[i]);
    }
    build(1, 1, N);
    scanf("%d", &M);
    for (int i = 0; i < M; ++i)
    {
        scanf("%d%d%d", &k, &l, &r);
        if (k == 0)
        {
            printf("%d\n", query(1, 1, N, l, r)[1]);
        }
        else
        {
            edit(1, 1, N, l, r);
        }
    }
    return 0;
}