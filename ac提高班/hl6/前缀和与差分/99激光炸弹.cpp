#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5010;

int n, r;
int s[N][N];

int getSum(int x2, int y2, int x1, int y1)
{
    return s[x2][y2] - s[x2][y1] - s[x1][y2] + s[x1][y1];
}

int main()
{
    cin >> n >> r;
    r = min(r, 5001); //细节1
    while (n -- )
    {
        int x, y, w;
        cin >> x >> y >> w;
        x ++ , y ++ ;
        s[x][y] += w;
    }
    
    for (int i = 1; i <= 5001; i ++ ) 
        for (int j = 1; j <= 5001; j ++ )   
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    
    
    int res = 0;
    for (int i = r; i <= 5001; i ++ ) //细节2
        for (int j = r; j <= 5001; j ++)
            res = max(res, getSum(i, j, i - r, j - r));
            
    cout << res << endl;
    
    return 0;
}