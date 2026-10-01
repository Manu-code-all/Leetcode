int dp[101][101][101];
int fun(int i,int j,vector<vector<char>>&grid,int a){
    int n=grid.size();
    int m=grid[0].size();
    if(i>=n || j>=m) return 0;

    int len=n+m-1;

    if(grid[i][j]=='(') a++;
    else a--;

    if(a>len/2 || a<0) return 0;

    if(i==n-1 && j==m-1){
        return a==0;
    }

    if(dp[i][j][a]!=-1) return dp[i][j][a];


    int c1=fun(i+1,j,grid,a);
    int c2=fun(i,j+1,grid,a);

    return dp[i][j][a]=c1|c2;
}
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp,-1,sizeof(dp));
        return fun(0,0,grid,0);
    }
};