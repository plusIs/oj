#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, l;
    char str1[1005], str2[1005];
    scanf("%d", &n);
    n %= 2;
    scanf("%s%s", str1, str2);
    l = strlen(str1);
    for (int i = 0; i < l; ++i)
    {
        if (n == 1)
        {
            if (str1[i] == '1')
                str1[i] = '0';
            else
                str1[i] = '1';
        }
    }
    if (strcmp(str1, str2) == 0)
        puts("Deletion succeeded");
    else
        puts("Deletion failed");
    return 0;
}