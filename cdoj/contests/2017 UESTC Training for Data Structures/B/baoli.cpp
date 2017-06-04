#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int data[100005];

int query(int l, int r)
{
    int m = 0, tmp = 0;
    /*for (int i = 0; i < 5; ++i)
        printf("%d ", data[i]);
    putchar('\n');*/
    for (int i = l; i <= r; ++i)
    {
        if (data[i] == 1)
        {
            ++tmp;
        }
        else if (tmp != 0)
        {
            m = max(m, tmp);
            tmp = 0;
        }
    }
    m = max(m, tmp);
    
    return m;
}

int edit(int l, int r)
{
    for (int i = l; i <= r; ++i)
    {
        data[i] ^= 1;
    }
}

int main()
{
    //freopen("data.in", "r", stdin);
    int N, M, k, l, r;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &data[i]);
    }
    scanf("%d", &M);
    for (int i = 0; i < M; ++i)
    {
        scanf("%d%d%d", &k, &l, &r);
        if (k == 0)
        {
            printf("%d\n", query(l - 1, r - 1));
        }
        else
        {
            edit(l - 1, r - 1);
        }
    }
    return 0;
}