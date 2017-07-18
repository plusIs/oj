#include <bits/stdc++.h>
using namespace std;
int data[6][6];
int main()
{
    int n;
    for (int i = 1; i <= 4; ++i)
    {
        for (int j = 1; j <= 4; ++j)
        {
            scanf("%d", &data[i][j]);
        }
    }

    scanf("%d", &n);
    if (n == 0)
    {
        for (int i = 1; i <= 4; ++i)
        {
            for (int j = 1; j <= 4; ++j)
            {
                if (data[i][j] == 0)
                {
                    for (int k = j + 1; k <= 4; ++k)
                    {
                        if (data[i][k] != 0)
                        {
                            swap(data[i][k], data[i][j]);
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= 4; ++i)
        {
            for (int j = 1; j <= 4; ++j)
            {
                //break;
                if (j < 4 && data[i][j] != 0 && data[i][j] == data[i][j + 1])
                {
                    data[i][j] *= 2;
                    for (int k = j + 1; k <= 4; ++k)
                        data[i][k] = data[i][k + 1];
                }
            }
        }
    }
    else if (n == 1)
    {
        for (int i = 1; i <= 4; ++i)
        {
            for (int j = 1; j <= 4; ++j)
            {
                if (data[i][j] == 0)
                {
                    for (int k = i + 1; k <= 4; ++k)
                    {
                        if (data[k][j] != 0)
                        {
                            swap(data[k][j], data[i][j]);
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= 4; ++i)
        {
            for (int j = 1; j <= 4; ++j)
            {
                if (i < 4 && data[i][j] != 0 && data[i][j] == data[i + 1][j])
                {
                    data[i][j] *= 2;
                    for (int k = i + 1; k <= 4; ++k)
                        data[k][j] = data[k + 1][j];
                }
            }
        }
    }
    else if (n == 2)
    {
        for (int i = 4; i >= 1; --i)
        {
            for (int j = 4; j >= 1; --j)
            {
                if (data[i][j] == 0)
                {
                    for (int k = j - 1; k >= 1; --k)
                    {
                        if (data[i][k] != 0)
                        {
                            swap(data[i][k], data[i][j]);
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 4; i >= 1; --i)
        {
            for (int j = 4; j >= 1; --j)
            {
                if (j > 1 && data[i][j] != 0 && data[i][j] == data[i][j - 1])
                {
                    data[i][j] *= 2;
                    for (int k = j - 1; k >= 1; --k)
                        data[i][k] = data[i][k - 1];
                    data[i][1] = 0;
                }
            }
        }
    }
    else if (n == 3)
    {
        for (int i = 4; i >= 1; --i)
        {
            for (int j = 4; j >= 1; --j)
            {
                if (data[i][j] == 0)
                {
                    for (int k = i - 1; k >= 1; --k)
                    {
                        if (data[k][j] != 0)
                        {
                            swap(data[k][j], data[i][j]);
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 4; i >= 1; --i)
        {
            for (int j = 4; j >= 1; --j)
            {
                if (i > 1 && data[i][j] != 0 && data[i][j] == data[i - 1][j])
                {
                    data[i][j] *= 2;
                    for (int k = i - 1; k >= 1; --k)
                        data[k][j] = data[k - 1][j];
                }
            }
        }
    }
    for (int i = 1; i <= 4; ++i)
    {
        for (int j = 1; j <= 4; ++j)
        {
            printf("%d ", data[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
