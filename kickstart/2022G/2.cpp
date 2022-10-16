#include <bits/stdc++.h>

using namespace std;

// typedef pair<int, int> PII;

// #define x first
// #define y second

const int N = 10;

int rs, rh, n, m;
double getr[N], gety[N]; 

double get_dist(int a, int b)
{
    return sqrt(a * a + b * b);
}

int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C ++ )
    {
        cin >> rs >> rh;
        double minr, miny;
        int limit = rs + rh;
        minr = miny = limit + 1;
        
        int scorer, scorey;
        scorer = scorey = 0;
        
        cin >> n;
        for (int i = 0; i < n; i ++ )
        {
            int a, b;
            cin >> a >> b;
            double d = get_dist(a, b);
            getr[i] = d;
            if (d < limit || abs(d - limit) <= 1e-19) 
            {
                scorer ++ ;
                minr = min(minr, d);
            }
        }
        cin >> m;
        for (int i = 0; i < m; i ++ )
        {
            int a, b;
            cin >> a >> b;
            double d = get_dist(a, b);
            gety[i] = d;
            if (d < limit || abs(d - limit) <= 1e-19) 
            {
                scorey ++ ;
                miny = min(miny, d);
            }
        }

        if (scorer && scorey)
        {
            if (minr < miny)
            {
                scorer = 0;
                for (int i = 0; i < n; i ++ )
                    if (getr[i] < miny)
                        scorer ++ ;
                scorey = 0;
            }

            else if (minr > miny)
            {
                scorey = 0;
                for (int i = 0; i < m; i ++ )
                    if (gety[i] < minr)
                        scorey ++ ;
                scorer = 0;
            }
        }

        printf("Case #%d: %d %d\n", C, scorer, scorey);
    }
    return 0;
}