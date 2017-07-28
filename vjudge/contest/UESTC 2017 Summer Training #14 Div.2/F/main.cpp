#include <bits/stdc++.h>
using namespace std;

int main()
{
    int result = 0;
    string str;
    getline(cin, str);
    result = str.size();
    for (size_t i = 0; i < str.size(); i += 3)
    {
        if (toupper(str[i] == 'P'))
            --result;
    }
    for (size_t i = 1; i < str.size(); i += 3)
    {
        if (toupper(str[i] == 'E'))
            --result;
    }
    for (size_t i = 2; i < str.size(); i += 3)
    {
        if (toupper(str[i] == 'R'))
            --result;
    }
    printf("%d\n", result);
    return 0;
}
