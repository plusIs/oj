#include <bits/stdc++.h>
using namespace std;
int data[1000005];
vector<int> switc;
int main()
{
    freopen("dales.in", "r", stdin);
    freopen("dales.out", "w", stdout);

    int T, n, ret1, ret2;
    scanf("%d", &T);
    while (T--)
    {
        ret1 = 0;
        ret2 = 0;
        scanf("%d", &n);
        switc.clear();
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &data[i]);
        }
        data[0] = data[1];
        data[n + 1] = data[n];
        for (int i = 1; i <= n; ++i)
        {
            int a = data[i] - data[i - 1], b = data[i] - data[i + 1];
            if ((a > 0 && b > 0) || (a < 0 && b < 0) || (a != 0 && b == 0) || (a == 0 && b != 0))
            {
                switc.push_back(i);
            }
        }
        for (size_t i = 0; i < switc.size(); ++i)
        {
            if (i > 0 && i < switc.size() - 1)
            {
                if (data[switc[i]] > data[switc[i] - 1] && data[switc[i]] > data[switc[i] + 1])
                    ret1 = max(ret1, min(switc[i] - switc[i - 1], switc[i + 1] - switc[i]));
                else if (data[switc[i]] < data[switc[i] - 1] && data[switc[i]] < data[switc[i] + 1])
                    ret2 = max(ret2, min(switc[i] - switc[i - 1], switc[i + 1] - switc[i]));
            }
            //printf("%d\n", switc[i]);
        }
        printf("%d %d\n", ret1, ret2);
        //putchar('\n');
    }
    return 0;
}
