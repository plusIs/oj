#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, result = 0;
    scanf("%d", &x);
    while (x >0)
    {
        if (x % 2 == 1)
            result += 1;
        x /= 2;
    }
    printf("%d\n", result);
    return 0;
}
