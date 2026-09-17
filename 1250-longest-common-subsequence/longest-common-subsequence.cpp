int dp[1001][1001];
int fun(int i,int j ,string &s,string &t){
    if(i>=s.size() || j>=t.size())return 0;

    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    if(s[i]==t[j]){
        int c1=1+fun(i+1,j+1,s,t);
        ans=max(ans,c1);
    }
    else{
        int c1=fun(i+1,j,s,t);
        int c2=fun(i,j+1,s,t);
        ans= max(ans,c2);
        ans=max(ans,c1);
    }
    return dp[i][j]=ans ;

}

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return fun(0,0,text1,text2);
    }
};