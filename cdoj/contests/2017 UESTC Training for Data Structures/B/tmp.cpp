#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#define MAXN 100000+10  
#define lson o<<1, l, mid  
#define rson o<<1|1, mid+1, r  
#define ll o<<1  
#define rr o<<1|1  
using namespace std;  
struct Tree  
{  
    int l, r, len;  
    int l1, r1, s1;  
    //区间从左开始的、从右开始的、整个区间、最多的连续的1的个数  
    int l0, r0, s0;  
    //区间从左开始的、从右开始的、整个区间、最多的连续的0的个数  
    int lazy;  
};  
Tree tree[MAXN<<2];  
void PushUp(int o)  
{  
    tree[o].l1 = tree[ll].l1;  
    tree[o].r1 = tree[rr].r1;  
    if(tree[ll].l1 == tree[ll].len)  
        tree[o].l1 += tree[rr].l1;  
    if(tree[rr].r1 == tree[rr].len)  
        tree[o].r1 += tree[ll].r1;  
    tree[o].s1 = max(max(tree[ll].s1, tree[rr].s1), tree[ll].r1 + tree[rr].l1);  
  
    tree[o].l0 = tree[ll].l0;  
    tree[o].r0 = tree[rr].r0;  
    if(tree[ll].l0 == tree[ll].len)  
        tree[o].l0 += tree[rr].l0;  
    if(tree[rr].r0 == tree[rr].len)  
        tree[o].r0 += tree[ll].r0;  
    tree[o].s0 = max(max(tree[ll].s0, tree[rr].s0), tree[ll].r0 + tree[rr].l0);  
}  
void build(int o, int l, int r)  
{  
    tree[o].l = l, tree[o].r = r;  
    tree[o].len = r - l + 1;  
    tree[o].lazy = 0;  
    if(l == r)  
    {  
        int x;  
        scanf("%d", &x);  
        tree[o].l1 = tree[o].r1 = tree[o].s1 = x ? 1 : 0;  
        tree[o].l0 = tree[o].r0 = tree[o].s0 = x ? 0 : 1;  
        return ;  
    }  
    int mid = (l + r) >> 1;  
    build(lson);  
    build(rson);  
    PushUp(o);  
}  
void change(int o)  
{  
    swap(tree[o].l1, tree[o].l0);  
    swap(tree[o].r1, tree[o].r0);  
    swap(tree[o].s1, tree[o].s0);  
    tree[o].lazy ^= 1;//注意 是异或。。。 连续两次修改之后不能再把信息向下传了  
}  
void PushDown(int o)  
{  
    if(tree[o].lazy)  
    {  
        //tree[ll].lazy = tree[rr].lazy = tree[o].lazy;  
        change(ll); change(rr);  
        tree[o].lazy = 0;  
    }  
}  
void update(int o, int L, int R)  
{  
    if(L <= tree[o].l && R >= tree[o].r)  
    {  
        change(o);  
        //tree[o].lazy = 1;  
        return ;  
    }  
    PushDown(o);  
    int mid = (tree[o].l + tree[o].r) >> 1;  
    if(R <= mid)  
        update(ll, L, R);  
    else if(L > mid)  
        update(rr, L, R);  
    else  
    {  
        update(ll, L, mid);  
        update(rr, mid+1, R);  
    }  
    PushUp(o);  
}  
int query(int o, int L, int R)  
{  
    if(L <= tree[o].l && R >= tree[o].r)  
        return tree[o].s1;  
    PushDown(o);  
    int mid = (tree[o].l + tree[o].r) >> 1;  
    if(R <= mid)  
        return query(ll, L, R);  
    else if(L > mid)  
        return query(rr, L, R);  
    else  
    {  
        int ans1 = query(ll, L, mid);  
        int ans2 = query(rr, mid+1, R);//查询时，拆分区间要注意  
        return max(max(ans1, ans2), min(mid-L+1, tree[ll].r1) + min(R-mid, tree[rr].l1));  
    }  
        //return max(query(ll, L, mid), query(rr, mid+1, R));  
}  
int main()  
{  
    int n;  
    while(scanf("%d", &n) != EOF)  
    {  
        build(1, 1, n);  
        int q, op, x, y;  
        scanf("%d", &q);  
        while(q--)  
        {  
            scanf("%d%d%d", &op, &x, &y);  
            if(op)  
                update(1, x, y);  
            else  
                printf("%d\n", query(1, x, y));  
        }  
    }  
    return 0;  
}  