#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
stack<ull> s1, s3;
set<ull> se;
int getLen(int n)
{
    int ret = 1;
    while (n / 10 != 0)
    {
        n /= 10;
        ++ret;
    }
    return ret;
}

ull myPow(ull x, ull y)
{
    ull ret = 1, now = x;
    while (y != 0)
    {
        if (y % (long long)2 != 0)
            ret = ret * now;
        now *= now;
        y /= 2;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    int n, result = 0, tmp;
    string str1, str2;
    cin >> n;
    cin.get();
    getline(cin, str1);
    getline(cin, str2);
    if (n > 1)
    {
        ull tmp1;
        s1 = s3;
        tmp = 0;
        for (size_t i = 0; i < str1.size(); ++i)
        {

            if (isdigit(str1[i]))
            {
                tmp += tmp * 10 + str1[i] - '0';
                continue;
            }
            if (tmp != 0)
            {
                tmp1 = myPow(233, tmp);
                se.insert(tmp1);
                s1.push(tmp1);
                tmp = 0;
            }
            if (str1[i] == ')')
            {
                ull a1, b1, c1;
                a1 = s1.top();
                s1.pop();
                b1 = s1.top();
                s1.pop();
                c1 = a1 + b1;

                s1.push(c1);
                se.insert(c1);
            }
        }

        s1 = s3;
        tmp = 0;
        for (size_t i = 0; i < str2.size(); ++i)
        {

            if (isdigit(str2[i]))
            {
                tmp += tmp * 10 + str2[i] - '0';
                continue;
            }
            if (tmp != 0)
            {
                tmp1 = myPow(233, tmp);
                s1.push(tmp1);
                if (se.find(tmp1) != se.end())
                    ++result;
                tmp = 0;
            }
            if (str2[i] == ')')
            {
                ull a1, b1, c1;
                a1 = s1.top();
                s1.pop();
                b1 = s1.top();
                s1.pop();
                c1 = a1 + b1;

                s1.push(c1);
                if (se.find(c1) != se.end())
                    ++result;
            }
        }
    }
    else
    {
        result = 1;
    }
    printf("%d\n", result);

    return 0;
}
