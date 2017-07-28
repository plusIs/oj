#include <bits/stdc++.h>
using namespace std;
int dp[100005][3], data[100005][3];

int getMax(int *array)
{
    return max(max(array[0], array[1]), array[2]);
}

int main()
{
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    for (int i = 0; i < x + y + z; ++i)
    {
        scanf("%d%d%d", &data[i][0], &data[i][1], &data[i][2]);
        for (int j = x; j >= 1; --j)
            dp[j][0] = max(getMax(dp[j]), getMax(dp[j - 1]) + data[i][0]);
        for (int j = y; j >= 1; --j)
            dp[j][1] = max(getMax(dp[j]), getMax(dp[j - 1]) + data[i][1]);
        for (int j = z; j >= 1; --j)
            dp[j][2] = max(getMax(dp[j]), getMax(dp[j - 1]) + data[i][2]);
    }
    printf("%d\n", max(max(getMax(dp[x]), getMax(dp[y])), getMax(dp[z])));
    return 0;
}