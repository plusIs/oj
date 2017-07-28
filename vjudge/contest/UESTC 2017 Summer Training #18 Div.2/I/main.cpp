#include <bits/stdc++.h>
using namespace std;
int data[200];

int getDist(int a, int b)
{
    bitset<64> bitA(a), bitB(b), tmp;
    tmp = bitA ^ bitB;
    return tmp.count();

}

int main()
{
    int n, T;
    scanf("%d", &T);
    while (T--)
    {
        int result = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &data[i]);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <=n; ++j)
            {
                result = max(result, getDist(data[i], data[j]));
            }
        }
        printf("%d\n", result);
    }

    return 0;
}
