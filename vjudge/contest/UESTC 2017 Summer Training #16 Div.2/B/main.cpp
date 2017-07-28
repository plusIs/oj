#include <bits/stdc++.h>
using namespace std;
int userKey[20], key[20];
int main()
{
    int n, m, result;
    while (scanf("%d%d", &m, &n) && m != 0 && n != 0)
    {
        result = 0;
        for (int i = 0; i < m; ++i)
            scanf("%d", &userKey[i]);
        for (int i = 0; i < n; ++i)
        {
            bool ok = true;
            for (int j = 0; j < m; ++j)
            {
                scanf("%d", &key[j]);
                if (key[j] > userKey[j])
                    ok = false;
            }
            if (ok)
                ++result;
        }
        printf("%d\n", result);
    }
    return 0;
}
