#include <bits/stdc++.h>
using namespace std;
int data[105], tmp[105];
int main()
{
    int n;
    bool result = true;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &data[i]);
    }
    for (int i = 2;i <= n; ++i)
    {
        if (data[i] == data[i - 1])
            tmp[i] = 0;
        else if (data[i] > data[i - 1])
            tmp[i] = 1;
        else
            tmp[i] = -1;
        //printf("%d ", tmp[i]);
    }
    //putchar('\n');
    for (int i = 2;i < n; ++i)
    {
        if (tmp[i] == 0 && tmp[i + 1] == 1)
            result = false;
        else if (tmp[i] == -1 && (tmp[i + 1] == 0 || tmp[i + 1] == 1))
            result = false;
    }
    if (result)
        puts("YES");
    else
        puts("NO");
    return 0;
}