#include <bits/stdc++.h>
using namespace std;
int data[25];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        for (int i = 1; i <= 20; ++i)
        {
            scanf("%d", &data[i]);
        }
        for (int i = 20; i > 1; --i)
        {
            data[i - 1] += data[i] / 2;
            data[i] %= 2;
        }
        for (int i = 1; i <20; ++i)
            printf("%d ", data[i]);
        printf("%d\n", data[20]);

    }
    return 0;
}
