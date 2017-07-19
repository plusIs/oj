#include <bits/stdc++.h>
using namespace std;
int hash1[3000050], hash2[3000050]; //29387  20407
vector<int> data1[300005], data2[300005];
int data1[300005], data2[300005];

vector<vector<int> *> q;

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

int myPow(int x, int y, int mod)
{
    int tmp[33], ret = 1;
    tmp[1] = x % mod;
    tmp[0] = 1;
    for (int i = 2; i <= 32; ++i)
    {
        tmp[i] = ((long long)tmp[i - 1] * (long long)tmp[i - 1]) % (long long)mod;
    }
    for (int i = 1; y != 0; ++i)
    {
        if (y % 2 == 1)
            ret *= tmp[i];
        ret %= mod;
        y /= 2;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    int n, result = 0, count1, count2, tmp;
    string str1, str2;
    cin >> n;
    cin.get();
    getline(cin, str1);
    getline(cin, str2);
    if (n > 1)
    {
        for (int i = 1; i <= n; ++i)
        {
            data1[i - 1].push_back(i);
            data2[i - 1].push_back(i);
        }
        count1 = n;
        q.clear();
        for (size_t i = 0; i < str1.size(); ++i)
        {
            if (str1[i] == '(')
            {
                q.push_back(&data1[count1++]);
            }
            else if (str1[i] == ')')
            {
                sort(q.back()->begin(), q.back()->end());
                q.pop_back();
            }
            else if (str1[i] != ',')
            {
                sscanf((char *)str1.c_str() + i, "%d", &tmp);
                i += getLen(tmp) - 1;
                for (auto each : q)
                {
                    each->push_back(tmp);
                }
            }
        }
        count2 = n;
        q.clear();
        for (size_t i = 0; i < str2.size(); ++i)
        {
            if (str2[i] == '(')
            {
                q.push_back(&data2[count2++]);
            }
            else if (str2[i] == ')')
            {
                sort(q.back()->begin(), q.back()->end());
                q.pop_back();
            }
            else if (str2[i] != ',')
            {
                sscanf((char *)str2.c_str() + i, "%d", &tmp);
                i += getLen(tmp) - 1;
                for (auto each : q)
                {
                    each->push_back(tmp);
                }
            }
        }
    }
    else
    {
        data1[0].push_back(1);
        data2[0].push_back(1);
        count1 = 1;
        count2 = 1;
    }
    for (int i = 0; i < count1; ++i)
    {
        int tmp1 = 0, tmp2 = 0;
        for (size_t j = 0; j < data1[i].size(); ++j)
        {
            tmp1 += data1[i][j] * myPow(n, j, 29387);
            tmp2 += data1[i][j] * myPow(n, j, 20407);
        }
        hash1[tmp1] = 1;
        hash2[tmp2] = 1;
    }
    for (int i = 0; i < count2; ++i)
    {
        int tmp1 = 0, tmp2 = 0;
        for (size_t j = 0; j < data2[i].size(); ++j)
        {
            tmp1 += data2[i][j] * myPow(n, j, 29387);
            tmp2 += data2[i][j] * myPow(n, j, 20407);
        }
        if (hash1[tmp1] == 1 && hash2[tmp2] == 1)
            ++result;
    }
    printf("%d\n", result);
    /*
    for (int i = 0; i < count1; ++i)
    {
        for (auto each : data1[i])
            printf("%d ", each);
        putchar('\n');
    }
    for (int i = 0; i < count2; ++i)
    {
        for (auto each : data2[i])
            printf("%d ", each);
        putchar('\n');
    }*/
    return 0;
}
