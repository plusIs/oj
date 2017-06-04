#include <bits/stdc++.h>
using namespace std;
#define MAXA 2005
#define MAXB 50005
//#define MAXB 10

int data[MAXA], d[MAXB], f[MAXB];

priority_queue<pair<int, int>,
               vector<pair<int, int>>,
               greater<pair<int, int>>>
    pr_que;

int main()
{
    //freopen("data.in", "r", stdin)
    int n, q, num;
    scanf("%d", &n);
    for (int i = 0; i < MAXB; ++i)
        d[i] = INT_MAX;
    for (int i = 0; i < n; ++i)
        scanf("%d", &data[i]);
    d[0] = 0;
    pr_que.push(pair<int, int>(d[0], 0));
    while (pr_que.empty() == false)
    {
        pair<int, int> tmp = pr_que.top();
        pr_que.pop();
        if (f[tmp.second] == 1)
            continue;
        f[tmp.second] = 1;

        for (int i = 1; i < n; ++i)
        {
            if (d[(data[i] + d[tmp.second]) % data[0]] > d[tmp.second] + data[i])
            {
                d[(data[i] + d[tmp.second]) % data[0]] = d[tmp.second] + data[i];
                pr_que.push(pair<int, int>(d[(data[i] + d[tmp.second]) % data[0]], (data[i] + d[tmp.second]) % data[0]));
            }
        }
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i)
    {
        scanf("%d", &num);
        if (d[num % data[0]] > num)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}