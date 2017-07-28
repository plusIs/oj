#include <bits/stdc++.h>
using namespace std;
bool charData[30];
string str, charSet, s;
int main()
{
    int n;
    ios::sync_with_stdio(false);
    getline(cin, charSet);
    getline(cin, s);
    for (size_t i = 0; i < charSet.size(); ++i)
        charData[charSet[i] - 'a'] = true;
    cin >> n;
    cin.get();
    for (int i = 0; i < n; ++i)
    {
        bool result = true;
        getline(cin, str);
        for (size_t j = 0; j < s.size(); ++j)
        {
            if (j >= str.size())
            {
                if (j != s.size() - 1 || s[j] != '*')
                    result = false;
                break;
            }
            else if (s[j] != str[j])
            {
                if (s[j] == '?')
                {
                    if (charData[str[j] - 'a'] == false)
                    {
                        result = false;
                        break;
                    }
                }
                else if (s[j] == '*')
                {
                    size_t l = j, r;
                    for (size_t k = 0;; ++k)
                    {
                        int pos1, pos2;
                        pos1 = s.size() - k - 1;
                        pos2 = str.size() - k - 1;
                        if (pos1 < 0 || pos2 < 0)
                        {
                            result = false;
                            break;
                        }
                        else if (s[pos1] != str[pos2])
                        {
                            if (s[pos1] == '?')
                            {
                                if (charData[str[pos2] - 'a'] == false)
                                {
                                    result = false;
                                    break;
                                }
                            }
                            else if (s[pos1] == '*')
                            {
                                r = pos2;
                                break;
                            }
                            else
                            {
                                result = false;
                                break;
                            }
                        }
                    }
                    if (l > r)
                    {
                        if (l != r + 1)
                            result = false;
                    }
                    else if (result == true)
                    {
                        for (size_t k = l; k <= r; ++k)
                        {
                            if (charData[str[k] - 'a'] == true)
                            {
                                result = false;
                                break;
                            }
                        }
                    }
                    break;
                }
                else
                {
                    result = false;
                    break;
                }
            }
            if (j == s.size() - 1)
            {
                if (s.size() != str.size())
                {
                    result = false;
                    break;
                }
            }
        }

        if (result)
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}