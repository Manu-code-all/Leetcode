int dp[501][501];
int fun(int i,int p,int m,vector<int>&nums,int k) {
        if(i>=nums.size())return 0;
        
        int len=i-p+1;
        if(dp[i][p]!=-1) return dp[i][p];
        m=max(m,nums[i]);
        int ans=0;
        if(len==k){
            int p=m*len +fun(i+1,i+1,0,nums,k);
            ans=max(ans,p);
        }
        else{
                int a=m*len +fun(i+1,i+1,0,nums,k);
                int b=fun(i+1,p,m,nums,k);
                ans=max(ans,a);
                ans=max(ans,b);
        }
        return dp[i][p]=ans;
    }

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return fun(0,0,0,arr,k);
    }
};