class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>m1;
        for(int i=0;i<nums.size();i++){
            int need=target-nums[i];
            if(m1.find(need)!=m1.end()){
                return {m1[need],i};
            }
            m1[nums[i]]=i;
        }
        return {};
    }
};