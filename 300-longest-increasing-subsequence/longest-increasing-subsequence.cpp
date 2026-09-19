class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>tmp;

        for(auto a:nums){
            if(tmp.size()==0 || a>tmp.back()){
                tmp.push_back(a);
            }else{
                for(int j=0;j<tmp.size();j++){
                    if(tmp[j]>=a){
                        tmp[j]=a;
                        break;
                    }
                }
            }
        }

        for(auto a:tmp) cout<<a<<" ";
        return tmp.size();
    }
};