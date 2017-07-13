#include <bits/stdc++.h>
using namespace std;
map<int, int> data_k, data_n, data_tmp;
int main()
{
    int k, n, tmp, now = 0, result = 0, x;
    scanf("%d%d", &k, &n);
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &tmp);
        now += tmp;
        data_k[now] = 1;
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &tmp);
        data_n[tmp] = 1;
    }
    for (auto each_k_1 : data_k)
    {
        x = tmp - each_k_1.first;
        data_tmp.clear();
        for (auto each_k_2 : data_k)
        {
            data_tmp[x + each_k_2.first] = 1;
        }
        ++result;
        for (auto each_n : data_n)
        {
            if (data_tmp.count(each_n.first) == 0)
            {
                --result;
                break;
            }
        }
    }
    printf("%d\n", result);
    return 0;
}