#include <bits/stdc++.h>
using namespace std;

int a[500005], b[250005], bData[250005];
priority_queue<pair<int, int>> q, qVoid;
int main()
{
    //freopen("data1.in", "r", stdin);
    int n, left;
    while (scanf("%d", &n) != EOF)
    {
        left = 0;
        q = qVoid;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(bData, 0, sizeof(bData));

        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            q.push(make_pair(a[i] - i, i));
        }
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &b[i]);
            ++bData[b[i]];
        }
        for (int i = n + 1; i <= 2 * n; ++i)
        {
            bool solve = false;
            while (solve == false)
            {
                pair<int, int> top = q.top();
                if (top.second <= left)
                {
                    q.pop();
                    continue;
                }
                else
                {
                    for (int j = top.second; j > left; --j)
                    {
                        if (bData[j] > 0)
                        {
                            --bData[j];
                            a[i] = top.first;
                            q.push(make_pair(a[i] - i, i));
                            solve = true;
                            //printf("a[i]=%d i=%d j=%d\n", a[i], i, j);

                            break;
                        }
                        else if (j == left + 1)
                        {
                            left = top.second;
                            q.pop();
                        }
                    }
                }
                //printf("top=[%d, %d] left=%d  ", top.first, top.second, left);
                //puts("fuck");
            }
        }

        long long result = 0;
        for (int i = n + 1; i <= 2 * n; ++i)
        {
            result = (result + a[i]) % 1000000007;
        }
        printf("%lld\n", result);
    }
    return 0;
}
