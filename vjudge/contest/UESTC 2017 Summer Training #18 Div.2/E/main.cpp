#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 70000
//#define MAXN 100

int order[MAXN], orderData[MAXN], data[MAXN], dataNum[MAXN], twoPow[70];

int main()
{
    //freopen("data1.in", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int i = 0; i <= 30; ++i)
        twoPow[i] = 1 << i;
    while (T--)
    {
        int n, maxData, now = 1, co = 1, tmp = 0;
        memset(orderData, 0, sizeof(orderData));
        memset(dataNum, 0, sizeof(dataNum));
        memset(order, 0, sizeof(order));

        for (n = 0;; ++n)
        {
            scanf("%d", &data[n]);
            if (data[n] == 0)
                break;
            ++dataNum[data[n]];
        }
        if (n == 0)
        {
            putchar('\n');
            continue;
        }
        sort(data, data + n);
        maxData = data[n - 1];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= 30; ++j)
            {
                if (data[i] == twoPow[j])
                {
                    order[data[i]] = n - tmp;
                    ++tmp;
                }
            }
        }

        while (3 * now <= maxData)
        {
            for (int i = 0; i < n; ++i)
            {
                if (data[i] % now == 0 && (data[i] / now) % 2 == 1 && order[data[i]] == 0)
                    order[data[i]] = co++;
            }
            now *= 2;
        }

        for (int i = 0; i < n; ++i)
            orderData[order[data[i]]] = data[i];
        co = 0;
        for (int i = 0; co < n; ++i)
        {
            for (int j = 0; j < dataNum[orderData[i]]; ++j)
            {
                ++co;
                if (co != n)
                    printf("%d ", orderData[i]);
                else
                    printf("%d\n", orderData[i]);
            }
        }
    }
    return 0;
}
