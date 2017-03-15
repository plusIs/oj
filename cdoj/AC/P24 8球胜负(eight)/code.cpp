#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int N, red, yellow;
    char str[16];
    bool flag;
    //freopen("data.in", "r", stdin);
    while(scanf("%d", &N) && N)
    {
        scanf("%s", str);
        red = 0;
        yellow = 0;
        for (int i =0; i < N; ++i)
        {
            if (str[i] == 'R')
            {
                ++red;
            }
            else if (str[i] == 'Y')
            {
                ++yellow;
            }
            else
            {
                if (str[i] == 'B')
                {
                    if (red == 7)
                        flag = true;
                    else
                        flag = false;
                }
                else
                {
                    if (yellow == 7)
                        flag = false;
                    else
                        flag = true;
                }
                if(flag)
                {
                    printf("Red\n");
                }
                else
                {
                    printf("Yellow\n");
                }
                break;
            }
        }

    }
    return 0;
}