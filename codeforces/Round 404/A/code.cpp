#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>

using namespace std;

map<char, int> data;

int main()
{
    ios::sync_with_stdio(false);
    data['T'] = 4;
    data['C'] = 6;
    data['O'] = 8;
    data['D'] = 12;
    data['I'] = 20;
    string str;
    long long ret = 0, n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        do
        {
            getline(cin, str);
        }while(str == "");
        ret += data[str[0]];
    }
    printf("%lld\n", ret);
    return 0;
}