#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, n;
    pair<int, int> data[15];
    scanf("%d", &T);
    while (T--)
    {
        int sum = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &data[i].first);
            sum += data[i].first;
            data[i].second = i + 1;
        }
        sort(data, data + n, greater<pair<int, int>>());
        //printf("%d\n", data[0].first);
        if (data[0].first > data[1].first)
        {
            if (data[0].first * 2 > sum)
                printf("majority winner %d\n", data[0].second);
            else
                printf("minority winner %d\n", data[0].second);
        }
        else
            printf("no winner\n");
        //for (int i = 0; data[i] == data[0]; ++i)
        //{

        //}
    }
    return 0;
}