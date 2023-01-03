// User function Template for C++

using toposort (we can use dikstras as well ) but this gives more better tc (0(n+m) + O(n+M);
here M is no of edges and n is no of vertices
class Solution {
  public:
  void solve(int src,vector<int>&vis,vector<pair<int,int>>graph[],stack<int>&s){
      vis[src]=1;
      for(auto child:graph[src]){
          int gNode=child.first;
          if(!vis[gNode]){
              solve(gNode,vis,graph,s);
          }
      }
      s.push(src);
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
        // vector<int>dist(N,INF);
        stack<int>st;
        solve(0,vis,graph,st);
        
      vector < int > dist(N);
      for (int i = 0; i < N; i++) {
        dist[i] = 1e9;
      }

      dist[0] = 0;
      while (!st.empty()) {
        int node = st.top();
        st.pop();

        for (auto it: graph[node]) {
          int v = it.first;
          int wt = it.second;

          if (dist[node] + wt < dist[v]) {
            dist[v] = wt + dist[node];
          }
        }
      }
      

      for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
      }
      return dist;
       
    }
};
