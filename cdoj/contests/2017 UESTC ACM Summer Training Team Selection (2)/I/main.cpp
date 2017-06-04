#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, tmp, out, newo;
    while (scanf("%d", &n) && n != 0)
    {
        n -= 3;
        if (n == 0)
            printf("4\n");
        else if (n <= 3 || n < 0)
            printf("No such base\n");
        else
        {
            tmp = sqrt(n) + 1;
            out = n;
            for (int i = 1; i <= tmp; ++i)
            {
                if (n % i == 0)
                {
                    if (i >= 4 && i < newo)
                        newo = i;
                    else if (n / i >= 4 && n/i < newo)
                        newo = n/i;
                    else
                        newo = out;
                    out = newo;
                }
            }
            printf("%d\n", out);
        }
    }
    return 0;
}