#include <bits/stdc++.h>
using namespace std;
bool isClosed, isFloorClosed;
struct POS
{
    int x = 0, y = 0, z = 0;
    POS(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    POS() {}
    bool operator<(const POS &p2) const
    {
        if (x < p2.x)
            return true;
        else if (x > p2.x)
            return false;
        else if (y < p2.y)
            return true;
        else if (y > p2.y)
            return false;
        else if (z < p2.z)
            return true;
        else
            return false;
    }
    bool operator == (const POS &p2) const
    {
        return x == p2.x && y == p2.y && z == p2.z;
    }
    bool operator != (const POS &p2) const
    {
        return !(*this==p2);
    }
};

map<pair<POS, POS>, bool> g1, g2;
map<POS, int> m1, m2;

int s1[100015], count1 = 1, s2[100015], count2 = 1;

int findRoot(int node, int *s)
{
    int r = node;
    if (s[r] != r)
    {
        s[r] = findRoot(s[r], s);
    }
    return s[r];
}

void insert(int r1, int r2, int *s)
{
    int r = findRoot(r1, s);
    s[r2] = r;
}

void connect1(POS &p1, POS &p2)
{
    int r1, r2;

    if (g1[pair<POS, POS>(p1, p2)] == true)
        return;

    else
    {
        g1[pair<POS, POS>(p1, p2)] = true;
        g1[pair<POS, POS>(p2, p1)] = true;
    }

    if (m1[p1] == 0)
    {
        //printf("0=%d %d\n", m1.count(p1), m1.count(p2));
        m1[p1] = count1++;

        //printf("1=%d %d\n", m1.count(p1), m1.count(p2));
        //printf("p1=(%d, %d, %d) p2=(%d, %d, %d) m1[p1]=%d m1[p2]=%d\n",
        //p1.x, p1.y, p1.z, p2.x, p2.y, p2.z, m1[p1], m2[POS(-1, -1, -1)]);
    }
    if (m1[p2] == 0)
    {
        m1[p2] = count1++;
    }
    //printf("connect1=%d %d %d\n", m1[p1], m1[p2], count1);
    r1 = findRoot(m1[p1], s1);
    r2 = findRoot(m1[p2], s1);

    if (r1 != r2)
        insert(r1, r2, s1);
    else if (p1 != p2)
    {
        //printf("p1=(%d, %d, %d) p2=(%d, %d, %d) r1=%d r2=%d m1[p1]=%d m1[p2]=%d\n",
               //p1.x, p1.y, p1.z, p2.x, p2.y, p2.z, r1, r2, m1[p1], m2[p2]);
        isClosed = true;
    }
}

void connect2(POS &p1, POS &p2)
{
    int r1, r2;
    p1.z = 0;
    p2.z = 0;
    if (g2[pair<POS, POS>(p1, p2)] == true)
        return;
    else
    {
        g2[pair<POS, POS>(p1, p2)] = true;
        g2[pair<POS, POS>(p2, p1)] = true;
    }
    if (m2[p1] == 0)
        m2[p1] = count2++;
    if (m2[p2] == 0)
        m2[p2] = count2++;
    //printf("connect2=%d %d %d\n", m2[p1], m2[p2], count2);
    
    r1 = findRoot(m2[p1], s2);
    r2 = findRoot(m2[p2], s2);
    if (r1 != r2)
        insert(r1, r2, s2);
    else if (p1 != p2)
    {
        //printf("p1=(%d, %d, %d) p2=(%d, %d, %d) r1=%d r2=%d m1[p1]=%d m1[p2]=%d\n",
               //p1.x, p1.y, p1.z, p2.x, p2.y, p2.z, r1, r2, m1[p1], m2[p2]);
        isFloorClosed = true;
    }
}

int main()
{
    int k;
    POS p1, p2;
    scanf("%d", &k);
    for (int i = 0; i <= 2 * k + 5; ++i)
    {
        s1[i] = i;
        s2[i] = i;
    }
    for (int i = 0; i < k; ++i)
    {
        scanf("%d%d%d%d%d%d", &p1.x, &p1.y, &p1.z, &p2.x, &p2.y, &p2.z);
        connect1(p1, p2);
        connect2(p1, p2);
    }
    if (isClosed)
        puts("True closed chains");
    else
        puts("No true closed chains");
    if (isFloorClosed)
        puts("Floor closed chains");
    else
        puts("No floor closed chains");
    return 0;
}
