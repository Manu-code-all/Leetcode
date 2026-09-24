int dp[1001][1001]; 
int fun(int i, int j, string &s1, string &s2) {
    if (i >= s1.size()) {
        int sum = 0;
        for (int k = j; k < s2.size(); k++) 
            sum += s2[k];
        return sum;
    }
    if (j >= s2.size()) {
        int sum = 0;
        for (int k = i; k < s1.size(); k++) 
            sum += s1[k];
        return sum;
    }
    if (dp[i][j] != -1) return dp[i][j];
    int m;
    if (s1[i] == s2[j]) {
        m = fun(i + 1, j + 1, s1, s2);
    } 
    else {
        int a = fun(i + 1, j, s1, s2) + s1[i];
        int b = fun(i, j + 1, s1, s2) + s2[j];
        m = min(a, b);
    }
    return dp[i][j] = m;
}
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        return fun(0, 0, s1, s2);
    }
};