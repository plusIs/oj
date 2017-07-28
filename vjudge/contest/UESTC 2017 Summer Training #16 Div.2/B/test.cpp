#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("data2.in", "w", stdout);
    int count = 0;
    puts("100");
    for (int i = 1; i < 10; ++i)
    {
        for (int j = 0; j < 9 * i + 7 && count < 100; ++j)
        {
            printf("%d %d\n", i, j);
            ++count;
        }
    }
    return 0;
}