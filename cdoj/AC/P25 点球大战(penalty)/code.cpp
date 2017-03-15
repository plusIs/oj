#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;
const char STR_NO[] = " no "; 
//no good
//0123456
char judge(string str)
{
    if (str.size() <= 7)
    {
        return 'O';
    }
    for (size_t i = 0; i < 4; ++i)
    {
        //printf("%s\n",&str.c_str()[i + str.size() - 8]);        
        if (str[i + str.size() - 8] != STR_NO[i])
        {
            return 'O';            
        }
    }
    return 'X';
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    int a[10], b[10], tmp, score_a, score_b;
    string str;
    //freopen("data.in", "r", stdin);
    while(cin >> n && (n != 0))
    {
        for (int i = 0; i < n; ++i)
        {
            do
            {
                getline(cin, str);
            }
            while(str == "");
            if (i % 2)
            {
                b[i / 2] = judge(str);
            }
            else
            {
                a[i / 2] = judge(str);
                b[i / 2] = '-';
            }
        }
        tmp = n / 2 + n % 2;
        score_a = 0;
        score_b = 0;        
        for (int i = 0; i < tmp; ++i)
        {
            printf("%d ", i + 1);
            if (a[i] == 'O')
                ++score_a;
            if (b[i] == 'O')
                ++score_b;
        }
        printf("Score\n");
        for (int i = 0; i < tmp; ++i)
        {
            printf("%c ", a[i]);
        }
        printf("%d\n", score_a);
        for (int i = 0; i < tmp; ++i)
        {
            printf("%c ", b[i]);
        }
        printf("%d\n", score_b);
    }
    return 0;
}