// f==0   house-1not robbed
// f==1   house -1 robbed


int dp[101][2];

int fun(int i,int f,vector<int>&nums){
   if(i==nums.size()-1){
      if(f==0) return nums[i];
      return 0;
   }

   if(i>=nums.size()){
    return 0;
   }

   if(dp[i][f]!=-1) return dp[i][f];


   int ans=0;
   

   if(i==0){
     int a=nums[i]+fun(i+2,1,nums);
     int b=fun(i+1,f,nums);
     ans=max(ans,a);
     ans=max(ans,b);
   }else{
     int a=nums[i]+fun(i+2,f,nums);
     int b=fun(i+1,f,nums);
     ans=max(ans,a);
     ans=max(ans,b);
   }

   return dp[i][f]=ans;
}

class Solution {
public:
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return fun(0,0,nums);
    }
};