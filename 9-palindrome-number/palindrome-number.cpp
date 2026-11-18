class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
            long long nums=0;
            int y=x;
            while(y>0){
                int r=y%10;
                nums=nums*10+r;
                y=y/10;
            }
            if(x==nums){
                return true;
            }
            else 
                return false;
        
        
    }
};