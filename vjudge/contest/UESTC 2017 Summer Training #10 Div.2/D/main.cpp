#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, minDay = 1, print = 1;
    scanf("%d", &n);
    while(true)
    {
        if (print < n)
        {
            print *= 2;
            minDay += 1;
        }
        else
            break;
    }
    printf("%d\n", minDay);
    return 0;
}
