#include <bits/stdc++.h>
using namespace std;
void diff(int a, int b);
int same[1000005], different[1000005];

int find(int x, int* data)
{
    int r = data[x];
    if(r != x)
        r = find(data[x], data);
    if (different[r] == 0)
        different[r] = different[x];
    data[x] = r;
    return r;
}


void join(int a, int b)
{
    int ra, rb;
    ra = find(a, same);
    rb = find(b, same);
    if (ra == rb)
        return;
    same[rb] = ra;
    if (different[ra] == 0)
        different[ra] = different[rb];
}

void diff(int a, int b)
{
    int ra, rb;
    ra = find(a, same);
    rb = find(b, same);
    if (ra == rb)
    {
        printf("NO\n");
        exit(0);
    }
    if (different[a])
        join(different[a], b);
    else
        different[a] = b;
    if (different[b])
        join(different[b], a);
    else
        different[b] = a;
}

int main()
{
    //freopen("data1.in", "r", stdin);
    int n, m, a, b, t;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <=n; ++i)
        same[i] = i;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &t, &a, &b);
        if (t == 1)
            join(a, b);
        if(t == 0)
            diff(a, b);
    }
    printf("YES\n");
    return 0;
}