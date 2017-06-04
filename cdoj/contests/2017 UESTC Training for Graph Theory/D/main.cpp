#include <bits/stdc++.h>
using namespace std;

int g[26][26], deg[26], ret[26], len[1005];
char str[1005][205];

priority_queue<int, vector<int>, greater<int>> pr_que;

int main()
{
    //freopen("data1.in", "r", stdin);
    int n, count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", str[i]);
        len[i] = strlen(str[i]);
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int l = min(len[i], len[i + 1]);
        for (int j = 0; j < l; ++j)
        {
            if (str[i][j] != str[i + 1][j])
            {
                if (g[str[i][j] - 'a'][str[i + 1][j] - 'a'] == 0)
                {
                    g[str[i][j] - 'a'][str[i + 1][j] - 'a'] = 1;
                    ++deg[str[i + 1][j] - 'a'];
                }
                break;
            }
            if (j == l - 1)
            {
                if (len[i] > len[i + 1])
                {
                    printf("-1\n");
                    return 0;
                }
            }
        }
    }
    for (int i = 0; i < 26; ++i)
    {
        if (deg[i] == 0)
        {
            pr_que.push(i);
        }
    }
    while (pr_que.empty() == false)
    {
        int u = pr_que.top();
        pr_que.pop();
        ret[count++] = u;
        for (int i = 0; i < 26; ++i)
        {
            if (g[u][i] == 1)
            {
                --deg[i];
                if (deg[i] == 0)
                {
                    pr_que.push(i);
                }
            }
        }
    }
    for (int i = 0; i < 26; ++i)
    {
        if (deg[i] != 0)
        {
            printf("-1\n");
            return 0;
        }
    }
    for (int i = 0; i < count; ++i)
    {
        putchar(ret[i] + 'a');
    }
    putchar('\n');
    return 0;
}