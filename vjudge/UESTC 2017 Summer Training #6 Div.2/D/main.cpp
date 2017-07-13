#include <bits/stdc++.h>
using namespace std;
int data[600006], data_index[600006];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; ++i)
    {
        scanf("%d", &data[i]);
        data_index[data[i]] = i;
    }
    sort(data+1, data + k + 1);
    for (int i = 1; i <= k; ++i)
    {
        for (int j = data[i] * 2; j <= n; j += data[i])
        {
            if (data_index[j] != 0)
            {
                printf("%d %d\n", data_index[j], data_index[data[i]]);
                return 0;
            }
        }
    }
    puts("0 0");
    return 0;
}
