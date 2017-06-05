#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
int data[MAXN], t[MAXN];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &data[i]);
    sort(data, data + n, greater<int>());
    for (int i = 0; i < n; ++i)
        t[i] = data[i] + i + 2;
    sort(t, t + n, greater<int>());
    printf("%d", t[0]);
    return 0;
}