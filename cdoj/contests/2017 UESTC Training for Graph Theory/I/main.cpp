#include <bits/stdc++.h>
using namespace std;

vector<int> g[1 << 16];
int path[1 << 16];
int pc = 0;
char ret[1 << 16];

void Euler(int u)
{
    for (int i = g[u].size() - 1; i >= 0;)
    {
        int v = g[u][i];
        g[u].pop_back();
        Euler(v);
        path[pc++] = v;
        i = g[u].size() - 1;
    }
}

int main()
{
    int n, n_2, n1, n2;
    scanf("%d", &n);
    if(n == 1)
        puts("01");
    n_2 = (1 << (n - 1));
    for (int i = 0; i < n_2; ++i)
    {
        n1 = (((n_2 >> 1) - 1) & i) << 1;
        n2 = n1 | 1;
        g[i].push_back(n1);
        for (int j = 0; j < g[i].size() - 1; ++j)
        {
            if (g[i][j] == n1)
            {
                g[i].pop_back();
                break;
            }
        }
        g[i].push_back(n2);
        for (int j = 0; j < g[i].size() - 1; ++j)
        {
            if (g[i][j] == n2)
            {
                g[i].pop_back();
                break;
            }
        }
    }
    Euler(0);
    path[pc++] = 0;
    for (int i = n - 2; i >= 0; --i)
    {
       //printf("%d", (path[pc - 1] >> i) & 1);
    }
    //putchar('\n');
    for (int i = pc - 1; i > 0; --i)
    {
        printf("%d", path[i] & 1);
        //printf("%d ", path[i]);
        
    }
    putchar('\n');
    
        //printf("%d ", path[i]);
    return 0;
}