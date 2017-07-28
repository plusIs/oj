#include <bits/stdc++.h>
using namespace std;
int result[20];
bool isQuest[10];
int main()
{
    int pos = 0, l = 0, r = 9;
    char ans;
    bool no = false, last = false;
    while (true)
    {
        printf("? ");
        for (int i = 1; i <= pos; ++i)
            printf("%d", result[i]);
        printf("%d", (l + r) / 2);
        putchar('\n');
        fflush(stdout);

        isQuest[(l + r) / 2] = true;
        ans = getchar();
        getchar();
        if (ans == 'N')
        {
            r = (l + r) / 2 - 1;
        }
        else
        {
            l = (l + r) / 2;
        }
        if (isQuest[(l + r) / 2] == true)
        {
            if ((l + r) / 2 + 1 <= 9 && isQuest[(l + r) / 2 + 1] == false)
            {
                l += 1;
                continue;
            }
            memset(isQuest, 0, sizeof(isQuest));
            result[++pos] = (l + r) / 2;
            if ((l + r) / 2 == 9)
            {
                printf("? ");
                for (int i = 1; i <= pos; ++i)
                    printf("%d", result[i]);
                printf("%d", 0);
                putchar('\n');
                fflush(stdout);

                isQuest[(l + r) / 2] = true;
                ans = getchar();
                getchar();
                if (ans == 'Y')
                {
                    break;
                }
            }
            l = 0;
            r = 9;
        }
    }
    return 0;
}
