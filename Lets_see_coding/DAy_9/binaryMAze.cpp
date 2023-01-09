// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        if(source.first==destination.first && source.second==destination.second) return 0;
        const int INF=1e9+7;
        vector<vector<int>>dist(n,vector<int>(m,INF));
        queue<pair<int,pair<int,int>>>q;
        dist[source.first][source.second]=0;
        q.push({0,{source.first,source.second}});
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        while(!q.empty()){
            auto d=q.front().first;
            auto r=q.front().second.first;
            auto c=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int newr=row[i]+r;
                int newc=col[i]+c;
                
                if(newr>=0 && newc>=0 && newr<n && newc<m && grid[newr][newc]==1 && 
                1+d<dist[newr][newc]){
                    dist[newr][newc]=1+d;
                    if(newr==destination.first && newc==destination.second){
                        return 1+d;
                    }
                    q.push({1+d,{newr,newc}});
                    
                }
            }
        }
        return -1;
        
        
        
    }
    
};