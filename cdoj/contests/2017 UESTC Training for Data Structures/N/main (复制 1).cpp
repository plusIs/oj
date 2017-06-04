#include <bits/stdc++.h>
using namespace std;
int data[1000005], different[1000005];
int find(int x)
{
    int r = x;
    if(data[r] != r)
        r = find(r);
    data[x] = r;
    return r;
}

void join(int a, int b)
{
    int ra = find(a), rb = find(b);
    data[rb] = ra;
}

void diff(int a, int b)
{
    int ra = find(a), rb = find(b);
    if (ra == rb)
    {
        printf("NO\n");
        exit(0);
    }
    if(different[ra] != 0 && different[ra] != rb)
        join(different[ra], rb);
    else
        different[ra] = rb;
    if(different[rb] != 0)
    {
        join(ra, different[rb]);
        different[rb] = 0;
    }
}

int main()
{
    freopen("data1.in", "r", stdin);
    int n, m, a, b, t;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <=n; ++i)
        data[i] = i;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &t, &a, &b);
        if (t == 1 && a!=b)
            join(a, b);
        if(t == 0)
        {
            if( a == b)
            {
                printf("NO\n");
                return 0;
            }
            else
                diff(a, b);
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", data[i]);
    printf("YES\n");
    return 0;
}