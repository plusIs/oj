#include <bits/stdc++.h>
using namespace std;
int v[100005];
vector<int> data;
stack<int> q;
int main()
{
    int n, s, l, r, result = 0;
    scanf("%d%d", &n, &s);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &v[i]);
    sort(v + 1, v + n + 1);
    l = 1;
    r = n;
    while (l <= r)
    {
        if (l != r && v[l] + v[r] > s)
        {
            data.push_back(v[l]);
            data.push_back(v[r]);
            //if (q.empty() == false)
            //{
                //data.push_back(q.top());
                //q.pop();
            //}
            ++l;
            --r;
        }
        else
        {
            q.push(v[l]);
            ++l;
        }
    }
    while (q.empty() == false)
    {
        data.push_back(q.top());
        q.pop();
    }
    for (int i = 0; i < n; ++i)
    {
        if (i == n - 1)
        {
            ++result;
            break;
        }
        //printf("i=%d data[i]=%d data[i+1]=%d result=%d\n", i, data[i], data[i + 1], result);
        if (data[i] + data[i + 1] > s)
        {
        }
        else
        {
            ++i;
        }
        ++result;
        //printf("%d\n", i);
    }
    printf("%d\n", result);
    for (size_t i = 0; i < data.size(); ++i)
    {
        if (i < data.size() - 1)
            printf("%d ", data[i]);
        else
            printf("%d\n", data[i]);
    }
    return 0;
}