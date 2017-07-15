#include <bits/stdc++.h>
using namespace std;
int data[20];

bool check(int tmp[20], int now)
{
    int tmp1[20];
    for (int i = 1; i <= 9; ++i)
    {
        if (tmp[i] == 3)
        {
            tmp[i] = 0;
            ++now;
            if (check(tmp, now))
                return true;
            tmp[i] = 3;
            --now;
        }
    }

    for (int i = 1; i <= 9; ++i)
    {
        tmp1[i] = tmp[i];
    }
    for (int i = 1; i <= 9; ++i)
    {
        if (tmp1[i] < 0)
        {
            return false;
        }
        if (tmp1[i] > 0)
        {
            tmp1[i + 1] -= tmp1[i];
            tmp1[i + 2] -= tmp1[i];
            now += tmp1[i];
            tmp1[i] = 0;
        }
    }
    if (now == 4)
        return true;
    else
        return false;
}

int main()
{
    //freopen("data1.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        for (int i = 1; i <= 9; ++i)
            data[i] = 0;
        for (int i = 1; i <= 14; ++i)
        {
            int tmp;
            scanf("%d", &tmp);
            ++data[tmp];
        }
        for (int i = 1; i <= 9; ++i)
        {
            if (data[i] >= 2)
            {
                data[i] -= 2;
                if (check(data, 0))
                    goto Vulnerable;
                else
                    data[i] += 2;
            }
        }
    Immune:
        puts("Immune");
        continue;
    Vulnerable:
        puts("Vulnerable");
        continue;
    }
    return 0;
}
