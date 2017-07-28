#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int main()
{
    int n, k, tmp, result = 0, out;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &tmp);
        if (q.empty() == false)
        {
            if (q.front() <= tmp)
                q.pop();
        }
        q.push(tmp + 1000);
        result = max(result, (int)q.size());
    }
    out = result / k;
    if (result % k != 0)
        ++out;
    printf("%d\n", out);
    return 0;
}
