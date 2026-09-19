class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;

        int z=0,m=0;

        while(j<nums.size()){
          if(nums[j]==0) z++;
          
          while(z>k){
            if(nums[i]==0) z--;
            i++;
          }

          m=max(m,j-i+1);

          j++;
        }

        return m;
    }
};