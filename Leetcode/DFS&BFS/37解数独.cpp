class Solution {
public:
    bool row[10][10], col[10][10], cell[3][3][10];
    int n = 9;
    int cnt;
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < n; j ++ ) {
                char c = board[i][j];
                if (c != '.') {
                    row[i][c-'0'] = true;
                    col[j][c-'0'] = true;
                    cell[i/3][j/3][c-'0'] = true;
                }
                else cnt ++ ;
            }
        dfs(board, 0, 0, 0);
    }

    bool dfs(vector<vector<char>>& board, int x, int y, int s) {
        if (y == n) x ++ , y = 0;
        if (x == n) {
           if (s == cnt) return true;
           return false;
        }

        if (board[x][y] != '.') return dfs(board, x, y + 1, s);
        
        for (int i = 1; i <= 9; i ++ ) {
            if (!row[x][i] && !col[y][i] && !cell[x/3][y/3][i]) {
                row[x][i] = col[y][i] = cell[x/3][y/3][i] = true;
                board[x][y] = i + '0';
                if (dfs(board, x, y + 1, s + 1)) return true;
                row[x][i] = col[y][i] = cell[x/3][y/3][i] = false;
                board[x][y] = '.';
            }
        }
        return false;
    }
};