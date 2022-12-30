//Number of Provinces

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  //with dfs
//   void solve(int source,vector<int>&vis,vector<int>graph[]){
//       vis[source]=1;
//       for(auto child:graph[source]){
//           if(!vis[child]){
//               solve(child,vis,graph);
//           }
//       }
//   }
  //with bfs
  void solve(int source,vector<int>&vis,vector<int>graph[]){
      vis[source]=1;
      queue<int>q;
      q.push(source);
      while(!q.empty()){
          auto node=q.front();
          q.pop();
          for(auto child:graph[node]){
              if(!vis[child]){
                  vis[child]=1;
                  q.push(child);
              }
          }
      }
  }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int n=adj.size();
        int m=adj[0].size();
        // vector<vector<int>>vis(n,vector<int>(m,0));
        vector<int>vis(V,0);
        vector<int>graph[V];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(adj[i][j]==1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int count=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                solve(i,vis,graph);
                count++;
            }
        }
        return count;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends