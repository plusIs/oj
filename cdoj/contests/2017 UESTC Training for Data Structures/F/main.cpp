#include <cstdio>
int dict_tree[100005 * 31][2];
int value[100005 * 31];
int cur_node = 1;

void insert(int x)
{
    int cur = 0, cur_bit;
    for (int i = 30; i >= 0; --i)
    {
        cur_bit = (x >> i) & 1;
        if(dict_tree[cur][cur_bit] == 0)
            dict_tree[cur][cur_bit] = cur_node++;
        cur = dict_tree[cur][cur_bit];
    }
    value[cur] = x;
}

int query(int x)
{
    int cur = 0, cur_bit;
    for (int i = 30; i >= 0; --i)
    {
        cur_bit = !((x >> i) & 1);
        if(dict_tree[cur][cur_bit] == 0)
            cur_bit = !cur_bit;
        cur = dict_tree[cur][cur_bit];
    }
    return value[cur];
}

int main()
{
    //freopen("data.in", "r", stdin);
    int n, tmp, m;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &tmp);
        insert(tmp);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &tmp);
        printf("%d\n", query(tmp) ^ tmp);
    }
    return 0;
}