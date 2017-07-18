#include <bits/stdc++.h>
using namespace std;
int main()
{
    int data1[4], data2[4];
    scanf("%d%d%d", &data1[0], &data1[1], &data1[2]);
    scanf("%d%d%d", &data2[0], &data2[1], &data2[2]);
    sort(data1, data1 + 3);
    sort(data2, data2 + 3);
    if (data1[0] == data2[0] && data1[1] == data2[1] && data1[2] == data2[2] &&
        data1[0] * data1[0] + data1[1] * data1[1] == data1[2] * data1[2])
    {
        puts("YES");
    }
    else
        puts("NO");
    return 0;
}