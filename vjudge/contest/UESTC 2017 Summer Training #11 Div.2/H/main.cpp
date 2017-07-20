#include <bits/stdc++.h>
using namespace std;
    char str[1000];

int main()
{
    freopen("kids.in","r", stdin);
    freopen("kids.out","w", stdout);
    
    int n, m;
    scanf("%d%d", &n, &m);
    double result = n;
    for (int i = 1; i <= m; ++i)
    {
        result = result *  (double)(n - 1);
        result = result / (double)n;
    }
    result = n - result;
    sprintf(str, "%.9f", result);
    for (int i = 998; i >= 0; --i)
    {
        if (str[i] == '0')
            str[i] = 0;
        else if(str[i] != 0)
            break;
    }
    //cout << result <<endl;
    //printf("%s\n", str);
    printf("%.9f\n", result);
    
    return 0;
}
