class Solution {
public:
    int n, m;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    void solve(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i ++ ) {
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }
        for (int j = 0; j < m; j ++ ) {
            dfs(board, 0, j);
            dfs(board, n - 1, j);
        }

        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ ) {
                if (board[i][j] == 'Y') board[i][j] = 'O';
                else board[i][j] = 'X';
            }  
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        if (board[x][y] == 'X') return;
        board[x][y] = 'Y';
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (board[x][y] == 'Y') continue;
            dfs(board, a, b);
        }
    }
};