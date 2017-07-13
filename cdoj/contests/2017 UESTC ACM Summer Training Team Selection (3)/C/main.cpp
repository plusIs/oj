#include <bits/stdc++.h>
using namespace std;
int main()
{
    double x, result;
    int ret;
    bool isPrint = false;
    scanf("%lf", &x);
    for (int i = 1; i <= 8; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            result = j * (pow(10, i) - 1) / (10 - x);
            ret = result + 0.5;
            if (abs(ret - result) < 1e-6 && ret / (int)pow(10, i - 1) == j)
            {
                isPrint = true;
                printf("%d\n", ret, i, j);
            }
        }
    }
    if (isPrint == false)
        puts("No solution");
    return 0;
}

