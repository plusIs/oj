#include <bits/stdc++.h>
using namespace std;
void diff(int a, int b);
int data[1000005], g[1000005];

int find(int x)
{
    int r = data[x];
    if(r != x)
        r = find(data[x]);
    g[x] = !(g[data[x]] ^ g[x]);
    data[x] = r;
    return r;
}


void join(int a, int b)
{
    int ra, rb;
    ra = find(a);
    rb = find(b);
    if (ra == rb)
    {
         if(g[b] == g[a])
            return;
        printf("NO\n");
        exit(0);
    }
    
    data[rb] = ra;
    g[rb] = !(g[b] ^ g[a]);
    //g[b] = g[a];
}

void diff(int a, int b)
{
    int ra, rb;
    ra = find(a);
    rb = find(b);
    if (ra == rb)
    {
         if(g[b] != g[a])
            return;
        printf("NO\n");
        exit(0);
    }
    data[rb] = ra;
    g[rb] = g[b] ^ g[a];
}

int main()
{
    freopen("data3.in", "r", stdin);
    int n, m, a, b, t;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <=n; ++i)
    {
        data[i] = i;
        g[i] = 1;
    }
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