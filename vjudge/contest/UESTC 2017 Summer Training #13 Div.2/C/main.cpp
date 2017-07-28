#include <bits/stdc++.h>
using namespace std;
vector<int> data;
int main()
{
    int n, k, tmp;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &tmp);
        data.push_back(tmp);
    }
    return 0;
}
