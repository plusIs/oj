#include <bits/stdc++.h>

using namespace std;
char str[100005];
bool data_map[100005];
int data[100005];

int main()
{
    int k, l, dataCount = 0;
    scanf("%d", &k);
    getchar();
    gets(str);
    l = strlen(str);
    for (int i = 0; i < l; ++i)
    {
        if (str[i] == '1')
        {
            data_map[i + 1] = true;
            data[dataCount++] = i + 1;
        }
    }
    for (int i = 0; i < dataCount; ++i)
    {
        for (int j = data[i]; j <= l; j += k)
        {
            if (data_map[j + 1] == true)
            {
                printf("%d %d\n", data[i], j + 1);
                return 0;
            }
        }
    }
    puts("0 0");
    return 0;
}
