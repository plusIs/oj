#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    cin.get();
    while (T--)
    {
        string str, nowStr;
        int sec = 0;
        nowStr.clear();
        while (getline(cin, str) && str != "END OF CASE")
        {
            ++sec;
            for (int i = 0; i < str.size(); ++i)
            {
                nowStr += str[i];
                if (str[i] == ';')
                {
                    cout << sec << ": " << nowStr << endl;
                    nowStr.clear();
                }
            }
        }
    }
    return 0;
}
