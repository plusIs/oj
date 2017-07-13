#include <bits/stdc++.h>
using namespace std;
map<long long, string> str_map;

void setB(long long a, long long &b)
{
    long long ret = 1, bLen = 0, tmp = b;
    while (true)
    {
        ++bLen;
        if (tmp < (long long)10)
            break;

        tmp /= (long long)10;
    }
    //cout << "bLen=" << bLen <<endl;
    ret = a / (long long)pow(10, bLen);
    ret *= (long long)pow(10, bLen);
    b += ret;
}

int main()
{
    ios::sync_with_stdio(false);
    long long n, a, b;
    string str;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        cin.get();
        cin.get();
        cin >> b;
        cin.get();
        getline(cin, str);
        //cout << a << ' ' << b << ' ' << str << endl;
        setB(a, b);
        for (long long j = a; j <= b; ++j)
        {
            if (str_map.count(i) == 0)
            {
                for (long long k = i; k > 0; k /= 10)
                {
                    if (str_map.count(k) != 0)
                        break;
                    else if (k < 10)
                        str_map[i] = str;
                }
            }
        }
    }
    for (auto each : str_map)
    {
        cout << each.first << ' ' << each.second << endl;
    }
    return 0;
}
