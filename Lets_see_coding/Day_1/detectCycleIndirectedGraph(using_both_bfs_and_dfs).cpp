class Solution {
    private:
    bool dfs(int source,vector<int>&vis,vector<int>&unmark,vector<int>adj[]){
        vis[source]=1;
        unmark[source]=1;
        for(auto child:adj[source]){
           if(!vis[child]){
               if(dfs(child,vis,unmark,adj)) return true;
           }
           if(vis[child]&&unmark[child]) return true;
        }
        unmark[source]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0),unmark(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,unmark,adj)) return true;
            }
        }
        return false;
    }
};