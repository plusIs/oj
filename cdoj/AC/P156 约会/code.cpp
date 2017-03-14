#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    //freopen("data.in", "r", stdin);
    while(scanf("%d", &n) && (n != 0))
    {
        printf("%d\n", 8 * n - 4);
    }
    return 0;
}