int dp[501][502][26];
int fun(int i,int k,int p,vector<int>&nums){
    if (i>=nums.size()) return 0;
    if(dp[i][p+1][k]!=-1) return dp[i][p+1][k];
    int m=0;
    if(p==-1||nums[i]==nums[p]){
        int a=1+fun(i+1,k,i,nums);
        m=max(m,a);
    }
    else if(k>0){
        int b=1+fun(i+1,k-1,i,nums);
        m=max(m,b);
    }
    int c=fun(i+1,k,p,nums);
    m=max(m,c);
    return dp[i][p+1][k]=m;

}
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        return fun(0,k,-1,nums);
    }
};