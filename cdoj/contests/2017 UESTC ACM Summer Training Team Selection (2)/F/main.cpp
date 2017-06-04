#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, n;
    char str[1000];
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        set<string> s;
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", str);
            s.insert(string(str));
        }
        printf("%d\n", (int)s.size());
        
    }
    return 0;
}