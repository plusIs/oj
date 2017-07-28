#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int, int>> g[100005];

ll timeData[100005], leafTime[100005], leaf;

void dfsCalcTime(int n)
{
    sort(g[n].begin(), g[n].end());
    for (auto &each : g[n])
    {
        timeData[each.second] = 2 * each.first - g[n][0].first + timeData[n];
        dfsCalcTime(each.second);
    }
    if (g[n].size() == 0)
        leafTime[leaf++] = timeData[n];
}

int main()
{
    ios::sync_with_stdio(false);
    int T, n, p, c, q;
    ll tmp;
    cin >> T;
    while (T--)
    {
        memset(timeData, 0, sizeof(timeData));
        memset(leafTime, 0, sizeof(leafTime));
        leaf = 0;
        cin >> n;
        for (int i = 0; i <= n; ++i)
            g[i].clear();
        for (int i = 2; i <= n; ++i)
        {
            cin >> p >>c;
            g[p].push_back(make_pair(c, i));
        }
        dfsCalcTime(1);
        sort(leafTime, leafTime + leaf);
        /*for (int i = 0; i <= n; ++i)
            printf("%lld\n", timeData[i]);
        *///for (int i = 0; i < leaf; ++i)
            //printf("leafTime=%lld\n", leafTime[i]);

        cin >> q;
        ll *pos;
        for (int i = 0; i < q; ++i)
        {
            cin >> tmp;
            pos = upper_bound(leafTime, leafTime + leaf, tmp);
            cout << (pos - leafTime) << endl;
        }
    }
    return 0;
}
