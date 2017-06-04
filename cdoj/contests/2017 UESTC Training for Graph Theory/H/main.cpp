#include <bits/stdc++.h>
#define MAX_N 1000005
//#define MAX_N 10


using namespace std;

struct Data
{
    int u, v, w;
    bool operator<(Data data) const
    {
        if (this->w < data.w)
            return true;
        else
            return false;
    }
} data[MAX_N];

int setData[MAX_N];

int find(int x)
{
    int r = setData[x];
    if(x != r)
        r = find(r);
    setData[x] = r;
    return r;
}

bool join(int x, int y)
{
    int rx, ry;
    rx = find(x);
    ry = find(y);
    if (rx != ry)
    {
        setData[ry] = rx;
        return true;
    }
    else
        return false;
}

int main()
{
    //freopen("data.in", "r", stdin);
    int n, count = 0, ret = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            data[count].u = i;
            data[count].v = j + 1;
            scanf("%d", &data[count].w);
            ++count;
        }
    }
    sort(data, data + count);
    for (int i = 0; i <= n; ++i)
        setData[i] = i;
    for (int i = 0; i < count; ++i)
    {
        if (join(data[i].u, data[i].v))
            ret += data[i].w;
    }
    printf("%d\n", ret);
    return 0;
}