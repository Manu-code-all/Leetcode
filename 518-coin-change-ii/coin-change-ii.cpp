vector<vector<int>> dp;
int fun(int i, vector<int>& coin, int amount){
    if(amount==0) return 1;
    if(i==coin.size()) return 0;
    if(dp[i][amount]!=-1) return dp[i][amount];
    int take=0;
    if(coin[i]<=amount){
        take = fun(i,coin,amount-coin[i]);
    }
    int notTake = fun(i+1,coin,amount);
    return dp[i][amount] = take + notTake;
}
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.assign(n+1, vector<int>(amount+1,-1));
        return fun(0,coins,amount);
    }
};