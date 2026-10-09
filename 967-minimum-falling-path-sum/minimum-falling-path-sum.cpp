int dp[101][101];
int fun(int x,int y,vector<vector<int>>&grid){
    int n=grid.size();
    int m=grid[0].size();
    if(x<0 || x>=n || y<0 || y>=m) return 1e9;
    if(x==n-1){
        return grid[x][y];
    }
    if(dp[x][y]!=-1e9){
        return dp[x][y];
    }
    int d=grid[x][y]+fun(x+1,y,grid);
    int r=grid[x][y]+fun(x+1,y+1,grid);
    int l=grid[x][y]+fun(x+1,y-1,grid);

    return dp[x][y]=min({d,r,l});
}


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=1e9;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                dp[i][j]=-1e9;
            }
        }
        for(int i=0;i<matrix[0].size();i++){
            ans=min(ans,fun(0,i,matrix));
        }
        return ans;
    }
};