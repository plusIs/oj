#include <bits/stdc++.h>
using namespace std;

struct Data
{
    char str[25];
    float weight;
    float percentage;
    float newWeight;
} data[25];

int main()
{
    int T, r, p, d, ma, count = 0;
    scanf("%d", &T);
    while (T--)
    {
        printf("Recipe # %d\n", ++count);
        scanf("%d%d%d", &r, &p, &d);
        for (int i = 0; i < r; ++i)
        {
            scanf("%s%f%f", data[i].str, &data[i].weight, &data[i].percentage);
            if (abs(data[i].percentage - 100.0) < 1e-8)
            {
                ma = i;
                data[i].newWeight = data[i].weight / p * d;
            }
        }
        for (int i = 0; i < r; ++i)
        {
            if (i != ma)
            {
                data[i].newWeight = data[ma].newWeight * data[i].percentage / 100;
            }
            printf("%s %.1f\n", data[i].str,data[i].newWeight);
        }
        puts("----------------------------------------");
    }
    return 0;
}