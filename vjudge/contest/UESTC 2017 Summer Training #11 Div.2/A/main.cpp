#include <bits/stdc++.h>
using namespace std;
bool data[11];
int main()
{
    freopen("bulls.in", "r", stdin);
    freopen("bulls.out", "w", stdout);
    
    int a = 0, b = 0;
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    for (auto each : str1)
    {
        data[each - '0'] = 1;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (str1[i] == str2[i])
            ++a;
        else if (data[str2[i] - '0'] == 1)
            ++b;
    }
    printf("%d %d\n", a, b);
    return 0;
}