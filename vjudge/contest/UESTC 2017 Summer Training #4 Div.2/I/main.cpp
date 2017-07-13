#include <bits/stdc++.h>
using namespace std;
int data1[1005], data2[1005];
int *r = data1, *b = data2;
int main()
{
    int s;
    //int tmp, count = 0;
    //scanf("%d", &tmp);
    while (scanf("%d", &s) != EOF)
    {
        int n, rNum = 0, bNum = 0, ret = 0;
        char c;
        for (int i = 0; i < s; ++i)
        {
            scanf("%d%c", &n, &c);
            if (c == 'R')
                r[rNum ++] = n;
            else
                b[bNum ++] = n;
        }
        sort(r, r + rNum, greater<int>());
        sort(b, b + bNum, greater<int>());
        if (rNum < bNum) //保证r永远大于b
        {
            swap(r, b);
            swap(rNum, bNum);
        }
        for (int i = 0; i < bNum; ++i)
        {
            ret += b[i];
            ret += r[i];
        }
        ret -= 2 *bNum;
        //++count;
        //printf("Case #%d: %d\n", count, ret);
        printf("%d\n", ret);
        
        getchar();
        getchar();
    }
    return 0;
}
