#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T, month1, month2, year1, year2;
    float result;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d%d", &month1, &year1, &month2, &year2);
        if (year1 == year2)
        {
            result = (month2 - month1) * (0.5 / (12 - month1 + 1));
        }
        else
        {
            result = ((year2 - year1 - 1) * 12 + month2 - 1)/12.0 + 0.5;
        }
        printf("%.4f\n", result);
    }
    return 0;
}
