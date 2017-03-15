#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>

using namespace std;

int main()
{    
    long long n, m, out;
    scanf("%lld", &n);
    long long  time_n_l[n], time_n_r[n];
    for (int i = 0; i < n; ++i)
    {
        scanf ("%lld%lld", &time_n_l[i], &time_n_r[i]);
    }
    scanf("%lld", &m);    
    long long time_m_l[m], time_m_r[m];
    for (int i = 0; i < m; ++i)
    {
        scanf ("%lld%lld", &time_m_l[i], &time_m_r[i]);
    }
    sort(time_n_l, time_n_l + n);
    sort(time_n_r, time_n_r + n);
    sort(time_m_l, time_m_l + m);
    sort(time_m_r, time_m_r + m);
    out = max(time_m_l[m - 1] - time_n_r[0], time_n_l[n - 1] - time_m_r[0]);
    if (out < 0)
        out = 0;
    printf("%lld\n", out);
    //printf("%lld %lld\n", time_m_l[m - 1] - time_n_r[0], time_n_l[n - 1] - time_m_r[0]);    
    return 0;
}