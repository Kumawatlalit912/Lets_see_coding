// User function Template for C++

toposort gives better time complexity  then dijkstra
const int INF=1e9;
class Solution {
  public:
  
  void solve(int src,vector<int>&vis,vector<pair<int,int>>graph[],vector<int>&dist,int N){
      vis[src]=0;
      dist[src]=0;
      multiset<pair<int,int>>s;
      s.insert({0,src});
      while(!s.empty()){
          auto f=*s.begin();
          int node=f.second;
          int dis=f.first;
          s.erase(f);
          if(vis[node]) continue;
          vis[node]=1;
          for(auto child:graph[node]){
              int gNode=child.first;
              int gdis=child.second;
              if(gdis+dis<dist[gNode]){
                  int fdis=gdis+dis;
                  dist[gNode]=fdis;
                  s.insert({fdis,gNode});
              }
          }
      }
      for(int i=0;i<N;i++){
          if(dist[i]==INF){
              dist[i]=-1;
          }
      }
  }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        int n=edges.size();
        int m=edges[0].size();
        vector<pair<int,int>>graph[N];
        for(int i=0;i<M;i++){
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        vector<int>vis(N,0);
        vector<int>dist(N,INF);
        solve(0,vis,graph,dist,N);
        return dist;
    }
};
