vector<vector<string>> ans;
vector<string> board;

// can a queen be placed at (i, j)?  looks at the rows above only
bool check(int i, int j, int n) {
    // same column
    for (int r = i - 1; r >= 0; r--) {
        if (board[r][j] == 'Q') return false;
    }
    // upper-left diagonal
    for (int r = i - 1, c = j - 1; r >= 0 && c >= 0; r--, c--) {
        if (board[r][c] == 'Q') return false;
    }
    // upper-right diagonal
    for (int r = i - 1, c = j + 1; r >= 0 && c < n; r--, c++) {
        if (board[r][c] == 'Q') return false;
    }
    return true;
}

// fill row i, then move to the rest
void fun(int i, int n) {
    if (i == n) {
        ans.push_back(board);
        return;
    }

    for (int j = 0; j < n; j++) {
        if (check(i, j, n)) {
            board[i][j] = 'Q';
            fun(i + 1, n);
            board[i][j] = '.';
        }
    }
}

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        board = vector<string>(n, string(n, '.'));
        fun(0, n);
        return ans;
    }
};