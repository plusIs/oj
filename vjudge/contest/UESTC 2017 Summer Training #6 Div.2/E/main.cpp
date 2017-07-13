#include <bits/stdc++.h>
using namespace std;
int table[10][10];
int testData[10][10][10][10][10];
int getE(int data[4])
{
    return table[table[table[table[0][data[0]]][data[1]]][data[2]]][data[3]];
}

int check(int data[4], int e)
{
    return table[getE(data)][e];
}

bool checkPos(int data[4], int pos)
{
    int data0[4] = {data[0], data[1], data[2], data[3]};
    for (int i = 0; i < 10; ++i)
    {
        data0[pos] = i;
        if (i != data[pos] && check(data0, getE(data)) == 0)
        {
            return false;
        }
    }
    if (pos < 3)
    {
        data0[pos] = data[pos];
        swap(data0[pos], data0[pos + 1]);
        if (data[pos] != data[pos + 1] && check(data0, getE(data)) == 0)
        {
            return false;
        }
    }

    return true;
}

bool checkEND(int data[4])
{
    int data0[4] = {data[0], data[1], data[2], data[3]}, e;
    e = getE(data);
    if (data0[3] != e)
    {
        swap(data0[3], e);
        if (check(data0, e) == 0)
            return false;
    }
    return true;
}

int main()
{
    //freopen("data.in", "r", stdin);
    int result = 0;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            scanf("%d", &table[i][j]);
        }
    }
    for (int i1 = 0; i1 < 10; ++i1)
    {
        for (int i2 = 0; i2 < 10; ++i2)
        {
            for (int i3 = 0; i3 < 10; ++i3)
            {
                for (int i4 = 0; i4 < 10; ++i4)
                {
                    int data[4] = {i1, i2, i3, i4};
                    int e = getE(data);
                    for (int i5 = 0; i5 < 10; ++i5)
                    {
                        if (i5 != e && check(data, i5) == 0) //验证末位
                        {
                            goto END;
                        }
                    }
                    for (int i5 = 0; i5 < 4; ++i5) //按位验证
                    {
                        if (checkPos(data, i5) == false)
                        {
                            goto END;
                        }
                    }
                    if (checkEND(data) == false)
                        goto END;
                    //printf("%d %d %d %d\n", data[0], data[1], data[2], data[3]);
                    continue;
                END:
                    ++result;
                }
            }
        }
    }
    printf("%d\n", result);
    return 0;
}
