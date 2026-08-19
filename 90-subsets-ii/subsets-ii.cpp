void fun(vector<int>&nums,vector<int>&tmp,vector<vector<int>>&ans,map<vector<int>,int>&m1){
    sort(tmp.begin(),tmp.end());
    if(m1.find(tmp)!=m1.end()) 
        return ;
    ans.push_back(tmp);
    m1[tmp]++;
    if(nums.size()==0){
        return ;
    }
    for(int i=0;i<nums.size();i++){
        vector<int>ip(nums),op(tmp);
        // ip={1,2,4} op={}
        op.push_back(nums[i]);
        for(int j=0;j<=i;j++)
        ip.erase(ip.begin());
        fun(ip,op,ans,m1);
    }
}
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>tmp;
        vector<vector<int>>ans;
        map<vector<int>,int>m1;
        fun(nums,tmp,ans,m1);
        sort(ans.begin(),ans.end());
        return ans;
    }
};