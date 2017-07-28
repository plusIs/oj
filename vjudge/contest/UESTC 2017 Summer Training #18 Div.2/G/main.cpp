#include <bits/stdc++.h>
//#include <cstdio>
using namespace std;
char str[200];

int main()
{
    //freopen("data1.in", "r", stdin);
    int D, d, n, last, l, tmp;
    scanf("%d", &D);
    for (int i = 0; i < D; ++i)
    {
        last = 0;
        scanf("%d", &d);
        getchar();
        gets(str);
        l = strlen(str);
        scanf("%d", &n);
        printf("%d ", d);
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &tmp);
            last = (last + tmp + l) % l;
            //printf("%d ", tmp);
            putchar(str[last]);
        }
        putchar('\n');
    }
    return 0;
}
