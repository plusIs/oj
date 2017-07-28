#include <bits/stdc++.h>
using namespace std;

char str1[80005], str2[80005];

int main()
{
    int T, n, x, y;
    scanf("%d", &T);
    while (T--)
    {
        int diff = 0;
        scanf("%d%d%d", &n, &x, &y);
        //getchar();
        scanf("%s%s", str1, str2);
        //gets(str1);
        //gets(str2);        
                
        if (x < y)
            swap(x, y);
        for (int i = 0; i < n; ++i)
        {
            if (str1[i] != str2[i])
                ++diff;
        }
        for (int i = 0; i <= n - diff; ++i)
        {
            int a = i, b = x - i, b1 = y - i;//a为相同部分正确个数 b为不同部分正确个数
            //printf("%d %d\n", b1, diff - b);
            if (b1 < 0 || b < 0)
                break;
            else if (b1 <= diff - b && b <= diff)
            {
                puts("Not lying");
                goto END;
            }
        }
        puts("Lying");
    END:;
    }
    return 0;
}
