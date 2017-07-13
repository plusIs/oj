#include <bits/stdc++.h>
using namespace std;
map<char, char> data;
int main()
{
    ios::sync_with_stdio(false);
    string str1, str2, str3;
    getline(cin, str1);
    getline(cin, str2);
    getline(cin, str3);
    for (int i = 0; i < 26; ++i)
    {
        data[str1[i]] = str2[i];
        data[toupper(str1[i])] = toupper(str2[i]);
    }
    for (int i = 0; i < str3.size();++i)
    {
        if (isalpha(str3[i]))
            str3[i] = data[str3[i]];
    }
    printf("%s\n", str3.c_str());
    return 0;
}