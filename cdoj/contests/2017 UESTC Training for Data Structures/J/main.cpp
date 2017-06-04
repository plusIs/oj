#include <queue>
#include <deque>
#include <cstdio>
using std::priority_queue;
using std::deque;
using std::greater;
priority_queue<int, deque<int>, greater<int>> p_queue;
int main()
{
    //freopen("data.in", "r", stdin);
    int n, tmp, ret = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &tmp);
        p_queue.push(tmp);
    }
    while(p_queue.size() > 1)
    {
        tmp = p_queue.top();
        p_queue.pop();    
        tmp += p_queue.top();
        p_queue.pop();            
        ret += tmp;
        p_queue.push(tmp);
    }
    printf("%d\n", ret);
    return 0;
}