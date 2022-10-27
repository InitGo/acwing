#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int, int> PII;

#define x first
#define y second

const int N = 155;

int n;
PII pos[N];
string g[N];
double d[N][N];
double maxd[N];

double get_dist(int i, int j)
{
    int dx = pos[i].x - pos[j].x;
    int dy = pos[i].y - pos[j].y;
    return sqrt(dx * dx + dy * dy);
}

void floyd()
{
    for (int k = 0; k < n; k ++ )
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < n; j ++ )
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> pos[i].x >> pos[i].y;
    for (int i = 0; i < n; i ++ ) cin >> g[i];

    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
        {
            if (i == j) d[i][j] = 0;
            else if (g[i][j] == '1') d[i][j] = get_dist(i, j);
            else d[i][j] = 1e20;
        }
    
    floyd();

    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            if (d[i][j] < 1e15)
                maxd[i] = max(maxd[i], d[i][j]);
    
    double res1 = 0;
    for (int i = 0; i < n; i ++ ) res1 = max(res1, maxd[i]);

    double res2 = 1e20;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            if (d[i][j] > 1e18)
                res2 = min(res2, get_dist(i, j) + maxd[i] + maxd[j]);
    
    printf("%.6lf\n", max(res1, res2));
    return 0;
}