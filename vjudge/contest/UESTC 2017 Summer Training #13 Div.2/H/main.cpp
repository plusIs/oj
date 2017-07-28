#include <bits/stdc++.h>
using namespace std;

string constStr[2] = {"+----------+----------+----------+", "|          |          |          |"},
       data[10][10];
int getWeek(const string &str)
{
    if (str == "Tuesday")
        return 1;
    else if (str == "Thursday")
        return 2;
    else
        return 3;
}

char tmpData[10][100];

int main()
{
    //freopen("data1.in", "r", stdin);
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string tmp, str;
        int num, week;

        cin.get();
        getline(cin, str);
        cin >> tmp;
        week = getWeek(tmp);
        cin >> num;
        data[num][week] = str;
    }
    for (int i = 1; i <= 4; ++i)
    {
        puts(constStr[0].c_str());
        int row = 1, nowRow;
        for (int j = 1; j <= 5; ++j)
            strcpy(tmpData[j], constStr[1].c_str());
        for (int j = 1; j <= 3; ++j)
        {
            nowRow = 0;
            char tmp[100][100];
            memset(tmp, 0, sizeof(tmp));
            strcpy(tmp[0], data[i][j].c_str());
            for (int k = 0; strlen(tmp[k]) > 10; ++k)
            {
                int stop = 10;
                for (int l = 10; l >= 0; --l)
                {
                    if (tmp[k][l] == ' ')
                    {
                        stop = l;
                        break;
                    }
                }
                tmp[k][stop] = 0;
                strcpy(tmp[k + 1], &tmp[k][stop + 1]);
            }
            for (int k = 0; strlen(tmp[k]) > 0; ++k)
            {
                ++nowRow;
                for (int l = 0; tmp[k][l] != 0; ++l)
                    tmpData[k + 1][(j - 1) * 11 + 1 + l] = tmp[k][l];
            }
            row = max(row, nowRow);
        }
        for (int j = 1; j <= row; ++j)
            puts(tmpData[j]);
    }
    puts(constStr[0].c_str());

    return 0;
}
