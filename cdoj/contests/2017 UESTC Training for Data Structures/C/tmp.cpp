#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 1 << 29, b;
    b = a;
    printf("%lld %lld", (long long)((long long)a * b), a);
    return 0;
}