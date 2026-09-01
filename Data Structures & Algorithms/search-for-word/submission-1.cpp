class Solution {
public:
    int n, m;

    bool dfs(int r, int c, int idx,
             vector<vector<char>>& board,
             const string& word) {

        // Current cell doesn't match
        if (board[r][c] != word[idx])
            return false;

        // Entire word found
        if (idx == word.size() - 1)
            return true;

        char temp = board[r][c];
        board[r][c] = '#';  // mark visited

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                board[nr][nc] != '#') {

                if (dfs(nr, nc, idx + 1, board, word)) {
                    board[r][c] = temp;
                    return true;
                }
            }
        }

        board[r][c] = temp;  // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] &&
                    dfs(i, j, 0, board, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};