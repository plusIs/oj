#include <bits/stdc++.h>
using namespace std;
// y 200005 x 100005
vector<int> data[200005]; //y到x 的映射
map<int, int> result[100005];
int pos[100005]; //x到y的映射
void update(int x, int y, int num)
{
    if (x > y)
        swap(x, y);
    if (result[x].count(y) == 0)
    {
        result[x][y] = num;
        if (x > 1 && result[x - 1].count(x) != 0 && result[x - 1][x] < num)
        {
            update(x - 1, y, num);
        }
    }
    if (result[y].count(x) == 0)
    {
        result[y][x] = num;
        if (result[y + 1].count(y) != 0 && result[y + 1][y] < num)
        {
            update(y, y + 1, num);
        }
    }
}

int main()
{
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &x, &y);
        data[y].push_back(x);
        pos[x] = y;
    }
    for (int i = 1; i <= n; ++i)
    {
        result[i][i] = 0;
        sort(data[i].begin(), data[i].end());
    }
    for (int i = 1; i <= n; ++i)
    {
        if (pos[x] != 0)
        {
            update(pos[x], pos[x] + 1, x);
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%d\n", result[i].size());
    return 0;
}
