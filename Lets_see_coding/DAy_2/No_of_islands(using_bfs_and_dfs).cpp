// No of islands using bfs and dfs


//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    // private:
    // void bfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis){
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     queue<pair<int,int>>q;
    //     q.push({i,j});
    //     while(!q.empty()){
    //         int row=q.front().first;
    //         int col=q.front().second;
    //         q.pop();
    //         for(int i=-1;i<=1;i++){
    //             for(int j=-1;j<=1;j++){
    //                 int r=row+i;
    //                 int c=col+j;
    //                 if(r>=0 && r<n && c>=0 && c<m && grid[r][c]=='1'&&!vis[r][c]){
    //                     vis[r][c]=1;
    //                     q.push({r,c});
    //                 }
    //             }
    //         }
            
    //     }
    // }
    private:
    void dfs(int r,int c,vector<vector<char>>&grid,vector<vector<int>>&vis){
        vis[r][c]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int row=i+r;
                int col=j+c;
                if(row>=0 && row<n && col>=0 && col<m && grid[row][col]=='1' && !vis[row][col])
                {
                    vis[row][col]=1;
                    dfs(row,col,grid,vis);
                }
            }
        }
        }
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,grid,vis);
                    count++;
                }
            }
        }
        return count;
    }
};
