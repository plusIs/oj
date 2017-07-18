#include <bits/stdc++.h>
using namespace std;
int data1[11], data2[11];//+ - * /
bool check(int x, int n)
{
    for (int i = 1; i <= n; ++i)
    {
        if(data1[i] == 1)
            x += data2[i];
        else if (data1[i] == 2)
        {
            x -= data2[i];
            if (x < 0)
                return false;
        }
        else if (data1[i] == 3)
            x *= data2[i];
        else
        {
            if (x % data2[i] != 0)
                return false;
            x /= data2[i];
        }
    }
    return true;
}
int main()
{
    int n, result = 0;
    char str[20];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s%d", str, &data2[i]);
        if (strcmp(str, "ADD") == 0)
            data1[i] = 1;
        else if (strcmp(str, "SUBTRACT") == 0)
            data1[i] = 2;
        else if (strcmp(str, "MULTIPLY") == 0)
            data1[i] = 3;
        else       
            data1[i] = 4;     
    }
    for (int i = 1; i <= 100; ++i)
    {
        if(check(i, n) == false)
            ++result;

    }
    printf("%d\n", result);
    return 0;
}
