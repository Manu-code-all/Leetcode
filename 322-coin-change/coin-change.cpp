vector<vector<int>> dp;

int fun(int i, vector<int>& nums, int target){
    if(target==0) return 0;
    if(i==nums.size() || target<0) return INT_MAX;
    if(dp[i][target]!=-1) return dp[i][target];

    int a = fun(i,nums,target-nums[i]);
    if(a != INT_MAX) a++;
    int b = fun(i+1,nums,target);

    return dp[i][target]=min(a,b);
}

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.assign(n+1, vector<int>(amount+1,-1));
        int ans = fun(0,coins,amount);
        return ans == INT_MAX ? -1 : ans;
    }
};