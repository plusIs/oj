#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b, b_a = 0, people, ret = 0;
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &people);
        if (people == 1)
        {
            if(a > 0)
                --a;
            else if (b > 0)
            {
                --b;
                ++b_a;
            }
            else if (b_a > 0)
            {
                --b_a;
            }
            else
                ++ret;
        }
        else
        {
            if (b > 0)
                --b;
            else
                ret += 2;
        }
    }
    printf("%d\n", ret);
    return 0;
}