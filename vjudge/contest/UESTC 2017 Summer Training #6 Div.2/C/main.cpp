#include <bits/stdc++.h>
using namespace std;
int data[1005][200], line[1005], maxLen[200];
string str[1005][200];
int main()
{
    freopen("alignment.in", "r", stdin);
    freopen("alignment.out", "w", stdout);
    
    ios::sync_with_stdio(false);
    string tmp;
    int lineNum;
    for (int i = 1; getline(cin, tmp); ++i)
    {
        stringstream ss(tmp);
        //printf("ascii=%d\n", tmp[tmp.size() - 1]);
        for (int j = 1; ss >> str[i][j]; ++j)
        {
            data[i][j] = str[i][j].size();
            if (data[i][j] > maxLen[j])
                maxLen[j] = data[i][j];
            //printf("%d ", maxLen[i]);
            //printf("%d %s ", data[i][j], str[i][j].c_str());
            ++line[i];
        }
        lineNum = i;
    }
    //printf("%d\n", lineNum);
    for (int i = 1; i <= lineNum; ++i)
    {
        for (int j = 1; j < line[i]; ++j)
            printf("%-*s", maxLen[j] + 1, str[i][j].c_str());
        //printf("%-*s", 50,str[i][j].c_str());

        printf("%s\n", str[i][line[i]].c_str());
    }
    return 0;
}
