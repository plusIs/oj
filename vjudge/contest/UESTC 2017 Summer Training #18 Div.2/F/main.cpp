#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T, a, b;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &a, &b);
        if  (a == b)
            puts("Square");
        else
            puts("Rectangle");
    }
    return 0;
}
