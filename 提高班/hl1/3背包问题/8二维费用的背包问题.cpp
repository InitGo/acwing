#include <iostream>

using namespace std;

const int N = 110;

int n, V, M;
int f[N][N];

int main()
{
    cin >> n >> V >> M;

    for (int i = 0; i < n; i ++ )
    {
        int v, m, w;
        cin >> v >> m >> w;
        for (int j = V; j >= v; j -- )
            for (int k = M; k >= m; k -- )
                f[j][k] = max(f[j][k], f[j - v][k - m] + w);
    }

    cout << f[V][M] << endl;

    return 0;
}