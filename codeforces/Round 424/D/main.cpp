#include <bits/stdc++.h>
using namespace std;
int dataN[1005], dataK[2005];
int main()
{
    int n, k, p, tmp, maxData = 0, minData = INT_MAX;
    scanf("%d%d%d", &n, &k, &p);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &tmp);
        dataN[i] = tmp;
        //dataN[i] = abs(tmp - p);
    }
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &tmp);
        dataK[i] = tmp;
        //dataK[i] = abs(tmp - p);
    }
    sort(dataN, dataN + n);
    sort(dataK, dataK + k);
    for (int i = 0; i < k - n + 1; ++i)
    {
        maxData = 0;
        for (int j = 0; j < n; ++j)
        {
            int now;
            if (dataN[j] <= p)
            {
                if (dataN[j] > dataK[j + i])
                    now = (dataN[j] - dataK[j + i]) * 2 + p - dataN[j];
                else if (dataK[j + i] > p)
                    now = p - dataN[j] + (dataK[j + i] - p) * 2;
                else
                    now = p - dataN[j];
            }
            else
            {
                if (dataN[j] < dataK[j + i])
                    now = (dataK[j + i] - dataN[j]) * 2 + dataN[j] - p;
                else if (dataK[j + i] < p)
                    now = dataN[j] - p + (p - dataK[j + i]) * 2;
                else
                    now = dataN[j] - p;
            }
            //printf("%d %d %d\n", now, dataN[j], dataK[j + i]);
            if (maxData < now)
                maxData = now;
        }
        if (minData > maxData)
            minData = maxData;
    }
    printf("%d\n", minData);
    return 0;
}