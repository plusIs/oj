#include <bits/stdc++.h>
using namespace std;
#define MAX_MN 1005 * 1005
//#define MAX_MN 10

char tmp[1005][1005];
vector<int> g[MAX_MN];
int f[MAX_MN], d[MAX_MN];

//bool cmp(const int &a, const int &b)
bool cmp(int a, int b)
{
    return d[a] > d[b];
}

struct cmp1  
{  
     bool operator ()(int x, int y)  
    {  
        return d[x] > d[y];//小的优先级高  
    }  
}; 

priority_queue<int, vector<int>, cmp1> q;


int main()
{
    //freopen("data1.in", "r", stdin);
    int n, m;
    scanf("%d%d", &m, &n);
    getchar();
    for (int i = 0; i < m; ++i)
    {
        gets(tmp[i]);
        for (int j = 0; j < n; ++j)
        {
            tmp[i][j] -= '0';
            if (i - tmp[i][j] >= 0)
            {
                g[i * n + j].push_back((i - tmp[i][j]) * n + j);
                //g[(i - tmp[i][j]) * m + j].push_back(i * m + j);
            }
            if (i + tmp[i][j] <= m - 1)
            {
                g[i * n + j].push_back((i + tmp[i][j]) * n + j);
                //g[(i + tmp[i][j]) * m + j].push_back(i * m + j);
            }
            if (j - tmp[i][j] >= 0)
            {
                g[i * n + j].push_back(i * n + j - tmp[i][j]);
                //g[i * m + j - tmp[i][j]].push_back(i * m + j);
            }
            if (j + tmp[i][j] <= n - 1)
            {
                g[i * n + j].push_back(i * n + j + tmp[i][j]);
                //g[i * m + j + tmp[i][j]].push_back(i * m + j);
            }
        }
    }
    /*
    printf("fuck!\n");
    for (int i = 0; i < m * n; ++i)
    {
        for(auto each :g[i])
            printf("%d ", each);
        putchar('\n');
    }*/
    for (int i = 0; i < m * n; ++i)
        d[i] = INT_MAX;
    d[0] = 0;
    q.push(0);
    while (q.empty() == false)
    {
        int node = q.top();
        q.pop();
        if (f[node] == 1)
        {
            break;
        }
        f[node] = 1;
        //printf("%d\n", node);
        for (auto each : g[node])
        {
            if (d[each] > d[node] + 1)
            {
                d[each] = d[node] + 1;
                q.push(each);
            }
        }
    }
    if (d[n * m - 1] == INT_MAX)
        puts("IMPOSSIBLE");
    else
        printf("%d\n", d[n * m - 1]);
    return 0;
}
