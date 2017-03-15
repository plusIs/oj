#include <cstdio>
#include <algorithm>

using namespace std;

struct BUG_DATA
{
    long long a, d, sub;
};

bool cmp(BUG_DATA a, BUG_DATA b)
{
    return a.sub < b.sub;
}

int main()
{
    long long T, n, out;
    BUG_DATA bug_data[200005];
    //freopen("data.in", "r", stdin);
    scanf("%lld", &T);
    while (T--)
    {
        out = 0;
        scanf("%lld", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%lld%lld", &bug_data[i].a, &bug_data[i].d);
            bug_data[i].sub = bug_data[i].a - bug_data[i].d;
        }
        sort(bug_data, bug_data + n, cmp);

        for (int i = 0; i < n; ++i)
        {
            out += bug_data[i].sub * (i - (n - i - 1));
            //printf("%d %d %d out = %d\n", bug_data[i].a, bug_data[i].d, bug_data[i].sub, out);
        }
        printf("%lld\n", out);
    }
    return 0;
}