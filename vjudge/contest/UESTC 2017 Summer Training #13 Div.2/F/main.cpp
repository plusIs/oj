#include <bits/stdc++.h>
using namespace std;
pair<int, int> data[20], value[1000000];
unsigned int dp[1000000];

int main()
{
    int T, now, n, year;
    scanf("%d", &T);
    while (T--)
    {
        memset(dp, -1, sizeof(dp));
        scanf("%d%d", &now, &year, &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &data[i].first, &data[i].second);
            dp[data[i].second] = data[i].first;
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = data[i].second; j < 1000000; ++j)
            {
                dp[j - data[i].second] = min(dp[j - data[i].second], dp[j] - data[i].first);
            }
        }
        
    }
    return 0;
}
