#include <bits/stdc++.h>
using namespace std;
char str[10000000];
string str_data[1000000];
//vector<int> data[1000000];
//map<string, int> str_map;
int main()
{
    int n, t, x, maxLen = 0, last = 0;
    ios::sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> str_data[i] >> t;
        for (int j = 0; j < t; ++j)
        {
            cin >> x;
            //data[str_data[i].size()].push_back(i);
            //if (str_data[i].size() > maxLen)
                //maxLen = str_data[i].size();
            //str_map[str_data[i]] = i;
            if (x + str_data[i].size() - 1 > last)
            {
                last = x + str_data[i].size() - 1;
            }
            for (int k = 0; k < str_data[i].size(); ++k)
            {
                str[x - 1 + k] = str_data[i][k];
            }
        }
    }
    for (int i = 0; i < last; ++i)
    {
        if (str[i] == 0)
            str[i] = 'a';
    }
    puts(str);
    return 0;
}