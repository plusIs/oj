#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>


using namespace std;
bool data[201][201];

int W, H;
int nim[205][205];

int sg(int W, int H) {
    if (~nim[W][H]) return nim[W][H];
    set<int> xst;
    for (int i = 2; i + 1 < W; ++i)
        xst.insert(sg(i, H) ^ sg(W - i, H));
    for (int i = 2; i + 1 < H; ++i)
        xst.insert(sg(W, i) ^ sg(W, H - i));
    for (int i = 0; ; ++i)
        if (xst.find(i) == xst.end())
            return nim[W][H] = i;
}

int main()
{
    memset(nim, -1, sizeof nim);
    for (int i = 1; i <= 200; ++i)
    {
        data[1][i] = true;
        data[i][1] = true;
    }
    for (int i = 1; i <= 200; ++i)
    {
        for (int j = 1; j <= 200; ++j)
        {
            if (data[i][j] == false)
            {
                for (int k = 1; k < i; ++k)
                {
                    if (data[k][j] == false && data[i - k][j] == false)
                    {
                        data[i][j] = true;
                        data[j][i] = true;
                        break;
                    }
                }
                for (int k = 1; k < j; ++k)
                {
                    if (data[i][k] == false && data[i][j - k] == false)
                    {
                        data[i][j] = true;
                        data[j][i] = true;
                        break;
                    }
                }
            }
        }
    }
    int l, r;
    printf("%d\n", data[2][4]);
    for (int i = 2; i <= 200; ++i)
    {
        for (int j = 2; j <= 200; ++j)
        {
            if ((bool)data[i][j] != (bool)sg(i, j))
            {
                
                //printf("%d %d data[i][j]=%d sg=%d\n", i, j, data[i][j], sg(i, j));
                return 0;
            }
        }
    }
    return 0;
}
