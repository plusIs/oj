#include <bits/stdc++.h>
using namespace std;
bool g[500][500];
int x[505], y[505];

double PI, esp = 1e-5;

bool calc(int x, int y, double centerX, double centerY, double r2, double angle, int n)
{
    double jiAngle, dx, dy, xPos, yPos;
    int xInt, yInt;
    if (n == 3)
    {
        xInt = (int)(centerX + 0.5);
        yInt = (int)(centerY + 0.5);
        if (abs(xInt - centerX) <= esp && abs(yInt - centerY) <= esp &&
            xInt >= 0 && xInt <= 300 &&
            yInt >= 0 && yInt <= 300 &&
            g[xInt][yInt] == true)
            return true;
    }
    dx = x - centerX;
    dy = y - centerY;
    if (abs(dx) <= esp)
        jiAngle = PI / 2;
    else
        jiAngle = atan(dy / dx);
    if (dx < 0)
        jiAngle += PI;
    for (int i = 1; i < n; ++i)
    {
        xPos = centerX

    }
    return true;
}

int solve(int a, int b, int n)
{
    int dx, dy, d2, ret = 0;
    dx = x[a] - x[b];
    dy = y[a] - y[b];
    d2 = dx * dx + dy * dy;
    for (int i = 3; i <= n; ++i)
    {
        double centerX1, centerY1, centerX2, centerY2, r2, angle, h, tmp;
        angle = PI / n;
        r2 = (double)d2 / (2.0 * (1 - cos(angle)));
        h = sqrt(r2) * cos(PI / n / 2);
        centerX1 = (x[a] + x[b]) / 2.0;
        centerX2 = (x[a] + x[b]) / 2.0;
        centerY1 = (y[a] + y[b]) / 2.0;
        centerY2 = (y[a] + y[b]) / 2.0;
        if (y[a] != y[b])
        {
            tmp = h / sqrt((double)(dx * dx) / (double)(dy * dy) + 1);
            centerX1 += tmp;
            centerX2 -= tmp;
        }
        if (x[a] != x[b])
        {
            tmp = h / sqrt((double)(dy * dy) / (double)(dx * dx) + 1);
            centerY1 -= tmp;
            centerY2 += tmp;
        }
        if (calc(x[a], y[a], centerX1, centerY1, r2, angle, n))
            ++ret;
        if (calc(x[a], y[a], centerX2, centerY2, r2, angle, n))
            ++ret;
    }
}

int main()
{
    int n;
    PI = acos(-1);
    while (scanf("%d", &n) != EOF)
    {
        int result = 0 memset(g, 0, sizeof(g));
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &x[i], &y[i]);
            x[i] += 100;
            y[i] += 100;
            g[x[i]][y[i]] = true;
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                result += solve(i, j, n);
            }
        }
        printf("%d\n", result);
    }
    return 0;
}
