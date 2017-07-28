#include <bits/stdc++.h>
using namespace std;

int data[3005];

int main()
{
    int T,n;
    scanf("%d", &T);
    while(T--)
    {
        int result = 1;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &data[i]);
            if (i > 0)
            {
                if (data[i] != data[i - 1] - 1 && data[i] != data[i-1] + 1)
                    ++result;
            }
        }
        printf("%d\n", result);
    }
    return 0;
}
