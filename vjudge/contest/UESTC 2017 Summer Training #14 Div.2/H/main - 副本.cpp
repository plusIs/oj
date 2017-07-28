#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, string> Class; //编号 星期 名字 name处理的位置；

Class data[15];
string constStr[2] = {"+----------+----------+----------+", "|          |          |          |"};
int getWeek(const string &str)
{
    if (str == "Tuesday")
        return 2;
    else if (str == "Thursday")
        return 4;
    else
        return 6;
}

char tmpData[10][100];

int main()
{
    //freopen("data1.in", "r", stdin);
    int n;
    string str;
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin.get();
        getline(cin, get<2>(data[i]));
        cin >> str;
        get<1>(data[i]) = getWeek(str);
        cin >> get<0>(data[i]);
    }
    sort(data, data + n);
    int count = 0;
    for (int i = 1; i <= 4; ++i)
    {
        puts(constStr[0].c_str());
        for (int j = 1; j <= 9; ++j)
            strcpy(tmpData[j], constStr[1].c_str());
        int row = 1;
        if (count < n && get<0>(data[count]) == i)
        {
            int nowRow, left;
            vector<int> spacePos;
            //printf("1.%d %d %d %d %s\n", count, get<1>(data[count]), get<0>(data[count]), i, get<2>(data[count]).c_str());
            if (count < n && get<1>(data[count]) == 2)
            {
                nowRow = 0;
                left = 0;
                spacePos.clear();
                for (size_t j = 0; j < get<2>(data[count]).size(); ++j)
                {
                    if (get<2>(data[count])[j] == ' ')
                        spacePos.push_back(j);
                }
                spacePos.push_back(get<2>(data[count]).size());
                for (size_t j = 0; j < spacePos.size(); ++j)
                {
                    if (j == spacePos.size() - 1 || spacePos[j + 1] - left > 10)
                    {
                        ++nowRow;
                        for (int k = left; k < spacePos[j]; ++k)
                            tmpData[nowRow][1 + k - left] = get<2>(data[count])[k];
                        left = spacePos[j] + 1;
                    }
                }
                row = max(row, nowRow);
                ++count;
            }
            //printf("2.%d %d %d %d %s\n", count, get<1>(data[count]), get<0>(data[count]), i, get<2>(data[count]).c_str());

            if (count < n && get<1>(data[count]) == 4)
            {
                nowRow = 0;
                left = 0;
                spacePos.clear();
                for (size_t j = 0; j < get<2>(data[count]).size(); ++j)
                {
                    if (get<2>(data[count])[j] == ' ')
                        spacePos.push_back(j);
                }
                spacePos.push_back(get<2>(data[count]).size());
                for (size_t j = 0; j < spacePos.size(); ++j)
                {
                    if (j == spacePos.size() - 1 || spacePos[j + 1] - left > 10)
                    {
                        ++nowRow;
                        for (int k = left; k < spacePos[j]; ++k)
                            tmpData[nowRow][12 + k - left] = get<2>(data[count])[k];
                        left = spacePos[j] + 1;
                    }
                }
                row = max(row, nowRow);
                ++count;
            }
            //printf("3.%d %d %d %d %s\n", count, get<1>(data[count]), get<0>(data[count]), i, get<2>(data[count]).c_str());

            if (count < n && get<1>(data[count]) == 6)
            {
                nowRow = 0;
                left = 0;
                spacePos.clear();
                for (size_t j = 0; j < get<2>(data[count]).size(); ++j)
                {
                    if (get<2>(data[count])[j] == ' ')
                        spacePos.push_back(j);
                }
                spacePos.push_back(get<2>(data[count]).size());
                for (size_t j = 0; j < spacePos.size(); ++j)
                {
                    if (j == spacePos.size() - 1 || spacePos[j + 1] - left > 10)
                    {
                        ++nowRow;
                        for (int k = left; k < spacePos[j]; ++k)
                            tmpData[nowRow][23 + k - left] = get<2>(data[count])[k];
                        left = spacePos[j] + 1;
                    }
                }
                row = max(row, nowRow);
                ++count;
            }
            //printf("4.%d %d %d %d %s\n", count, get<1>(data[count]), get<0>(data[count]), i, get<2>(data[count]).c_str());
        }
        for (int j = 1; j <= row; ++j)
            puts(tmpData[j]);
    }
    puts(constStr[0].c_str());

    return 0;
}
