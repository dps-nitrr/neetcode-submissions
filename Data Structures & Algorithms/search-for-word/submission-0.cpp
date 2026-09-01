class Solution {
public:
    int n, m;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    bool isValid(int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }

    bool dfs(int idx, int row, int col, string &word,
             vector<vector<char>>& board,
             vector<vector<bool>>& vis) {

        // Current character is already matched
        if (idx == word.size() - 1)
            return true;

        vis[row][col] = true;

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (isValid(nr, nc) &&
                !vis[nr][nc] &&
                board[nr][nc] == word[idx + 1]) {

                if (dfs(idx + 1, nr, nc, word, board, vis))
                    return true;
            }
        }

        // Backtracking
        vis[row][col] = false;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == word[0] &&
                    dfs(0, i, j, word, board, vis)) {
                    return true;
                }
            }
        }

        return false;
    }
};