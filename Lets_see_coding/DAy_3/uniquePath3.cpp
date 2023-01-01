unique path 3 leetcode --->980

class Solution {
public:
    int f(int i,int j,int c,int& empty,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==-1) return 0;        
        if(grid[i][j]==2){
            if(c==empty)
                return 1;
            return 0;
        }
        if(dp[i][j][c]!=-1)return dp[i][j][c];
        
        grid[i][j]=-1;
        int up=f(i-1,j,c+1,empty,grid,dp);
        int down=f(i+1,j,c+1,empty,grid,dp);
        int right=f(i,j+1,c+1,empty,grid,dp);
        int left=f(i,j-1,c+1,empty,grid,dp);
        grid[i][j]=0;
        return dp[i][j][c+1]=(up+down+right+left);        
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int i=0,j=0,empty=1,start_x=0,start_y=0;
        for(i;i<grid.size();i++){
            for(j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    start_x=i;
                    start_y=j;                    
                }
                if(grid[i][j]==0)
                    empty++;
            }
        }
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>> (grid[0].size(),vector<int> (empty+1,-1)));
        return f(start_x,start_y,0,empty,grid,dp);
    }
};