#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        set<pair<int, int>> s;
        s.clear();
        pair<int, int> tmp;
        int old;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &tmp.first, &tmp.second);
            old = s.size();
            s.insert(tmp);
            s.insert(pair<int, int>(tmp.second, tmp.first));
            
            if (old == s.size())
            {
                printf("impossible\n");
                break;
            }
            else if (i == n - 1)
            {
                printf("possible\n");
            }
        }
    }
    return 0;
}