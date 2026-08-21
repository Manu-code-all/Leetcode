void fun(string s,int n,int a,int b,vector<string> &ans){
   if(b>a)
        return;

    if(a>(n/2) || b >(n / 2))
        return;

    if( s.size() == n) {
        ans.push_back(s);
        return;
    }
    
    fun(s + "(", n, a + 1, b,ans);
    fun(s + ")", n, a, b + 1,ans);
}


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        fun("",2*n,0,0,ans);
        return ans;
    }
};