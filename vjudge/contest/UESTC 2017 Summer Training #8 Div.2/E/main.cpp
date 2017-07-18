#include <bits/stdc++.h>
using namespace std;
int data1[30], data2[200];
int main()
{
    char str[200];
    int l, del, result = 0;
    scanf("%s", str);
    l = strlen(str);
    for (int i = 0; i < l; ++i)
    {
        ++data1[str[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i)
    {
        ++data2[data1[i]];
    }
    del = 26 - data2[0];
    if (del <= 2)
    {
        puts("0");
        return 0;
    }
    del -= 2;
    for (int i = 1; i < 200; ++i)
    {
        if (del > data2[i])
        {
            del -= data2[i];
            result += data2[i] * i;
        }
        else
        {
            result += del * i;
            break;
        }
    }
    printf("%d\n", result);
    return 0;
}
