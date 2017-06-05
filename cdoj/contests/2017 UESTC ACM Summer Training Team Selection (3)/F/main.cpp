#include <bits/stdc++.h>
using namespace std;
char data[5][1005];
int numData[10][7] = {
    {1, 1, 1, 0, 1, 1, 1}, //0
    {0, 0, 1, 0, 0, 1, 0}, //1
    {1, 0, 1, 1, 1, 0, 1}, //2
    {1, 0, 1, 1, 0, 1, 1}, //3
    {0, 1, 1, 1, 0, 1, 0}, //4
    {1, 1, 0, 1, 0, 1, 1}, //5
    {1, 1, 0, 1, 1, 1, 1}, //6
    {1, 0, 1, 0, 0, 1, 0}, //7
    {1, 1, 1, 1, 1, 1, 1}, //8
    {1, 1, 1, 1, 0, 1, 1}, //9
};

bool isSharp(int x, int y, int type)
{
    if (type == 0)
    {
        if(data[x][y] == '*' && data[x][y + 1] == '*' && data[x][y + 2] == '*')
            return true;
    }
    else
    {
        if(data[x][y] == '*' && data[x + 1][y] == '*' && data[x + 2][y] == '*')
            return true;        
    }
    return false;
}

int calcNum(int pos)
{
    int numD[7];
    for (int i = 0; i < 7; ++i)
        numD[i] = 0;
    if (isSharp(0, pos, 0) == true)
        numD[0] = 1;
    if (isSharp(2, pos, 0) == true)
        numD[3] = 1;
    if (isSharp(4, pos, 0) == true)
        numD[6] = 1;
    if (isSharp(0, pos, 1) == true)
        numD[1] = 1;
    if (isSharp(2, pos, 1) == true)
        numD[4] = 1;
    if (isSharp(0, pos + 2, 1) == true)
        numD[2] = 1;
    if (isSharp(2, pos + 2, 1) == true)
        numD[5] = 1;
    
    //for (int i = 0; i < 7; ++i)
        //printf("%d ", numD[i]);
    //putchar('\n');
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            if (numD[j] != numData[i][j])
                break;
            else if (j == 6)
                return i;
        }
    }
    puts("BOOM!!");
    exit(0);
}

int main()
{
    int l, ret = 0;
    for (int i = 0; i < 5; ++i)
        gets(data[i]);
    l = (strlen(data[2]) + 1) / 4;
    for (int i = 0; i < l; ++i)
        ret += calcNum(i * 4) * pow(10, l - i - 1);
    if (ret % 6 == 0)
        puts("BEER!!");
    else
        puts("BOOM!!");
    //printf("%d", ret);
    return 0;
}