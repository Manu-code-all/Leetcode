int dp[13][10003];
int fun(int i,vector<int>&nums,int k){
    if(k==0) return 0;
    if(k<0 || i>=nums.size())   return 1e9;
    if(dp[i][k]!=-1) return dp[i][k];
    int c1=1+fun(i,nums,k-nums[i]);
    int c2=fun(i+1,nums,k);
    return dp[i][k]=min(c1,c2);
}
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans=fun(0,coins,amount);
        return ans==1e9 ? -1 : ans;
    }
};