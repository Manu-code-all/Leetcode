int dp[201][201];
int fun(int i, int j, vector<vector<int>>& grid) {
    if (i == 0 && j == 0) return grid[0][0];
    if (i < 0 || j < 0) return INT_MAX;
    if (dp[i][j] != -1) return dp[i][j];
    int up   = fun(i - 1, j, grid);
    int left = fun(i, j - 1, grid);
    return dp[i][j] = grid[i][j] + min(up, left);
}
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return fun(m - 1, n - 1, grid);
    }
};