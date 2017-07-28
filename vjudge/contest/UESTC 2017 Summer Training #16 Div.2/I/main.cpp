#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
char s[200];
ull data[200];

ull solve(int n)
{
    if (data[n] != 0)
        return data[n];
    else if (s[n] == 0)
        return 1;
    else if (s[n] == '0')
        return 0;
    else if (s[n + 1] == 0)
        data[n] = 1;
    else if ((s[n] - '0') * 10 + (s[n + 1] - '0') > 26)
        data[n] = solve(n + 1);
    else
    {
        data[n] = solve(n + 1);
        data[n] += solve(n + 2);
    }
    return data[n];
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        memset(data, 0, sizeof(data));
        scanf("%s", s);
        printf("Case #%d: %llu\n", i, solve(0));
    }
    return 0;
}
