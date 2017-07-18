#include <bits/stdc++.h>
using namespace std;
string str[105];
pair<string, string> data[105];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    cin.get();
    for (int i = 0; i < n; ++i)
        cin >> data[i].second >> data[i].first;
    sort(data, data + n);
    for (int i = 0; i < n; ++i)
        cout << data[i].second << " " << data[i].first << endl;
    return 0;
}
