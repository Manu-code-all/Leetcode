
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int s=0;
       map<int,int>m1;

       int count=0;

       for(auto a:nums){
        s+=a;
        if(s==k)count++;
        count+=m1[s-k];
        m1[s]++;

       } 
       return count;
    }
};