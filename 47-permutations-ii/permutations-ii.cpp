void fun(vector<int>&nums,vector<int>&tmp,vector<vector<int>>&ans){
    if(nums.size()==0){
    ans.push_back(tmp);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        vector<int>ip(nums),op(tmp);
        op.push_back(nums[i]);  
        ip.erase(ip.begin()+i);
        fun(ip,op,ans);
    }
}
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>tmp;
        vector<vector<int>>ans;
        fun(nums,tmp,ans);
       
        return ans;
    }  
};