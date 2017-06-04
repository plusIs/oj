#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

#define MAX 100000
#define Q 100000

int main()
{
    srand(time(0));
    int m = (rand()%MAX) + 1;
    printf("%d\n", m);
    printf("%d", rand()%2);
    for (int i = 1; i < m; ++i)
        printf(" %d", rand()%2);
    putchar('\n');
    int n = (rand()%Q) + 1;
    printf("%d\n", n);
     for (int i = 0; i < n; ++i)
     {
        printf("%d ", rand()%2);
        int l, r;
        l = rand()%m + 1;
        r = rand()%m + 1;
        if (l > r)
            swap(l, r);
        printf("%d %d\n", l, r);
        
     }
}
