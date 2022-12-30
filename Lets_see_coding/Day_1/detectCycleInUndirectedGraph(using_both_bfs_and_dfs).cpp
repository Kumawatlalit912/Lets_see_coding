//detect cycle in undirected graph using both bfs and dfs ===> lets seee


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

//using bfs

    // Function to detect cycle in an undirected graph.
    bool solve(int source,vector<int>&vis,vector<int>adj[],int parent){
        vis[source]=1;
        queue<pair<int,int>>q;
        q.push({source,parent});
        while(!q.empty()){
            int node=q.front().first;
            int par=q.front().second;
            q.pop();
            for(auto child:adj[node]){
                if(vis[child]&& child==par) continue;
                if(vis[child]) return true;
                vis[child]=1;
                q.push({child,node});
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        //using bfs
        
        vector<int>vis(V,0);
        bool ans=false;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                ans=ans|solve(i,vis,adj,-1);
            }
        }
        if(ans) return true;
        return false;
        
        
    }
};

//using dfs

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool solve(int source,vector<int>&vis,vector<int>adj[],int parent){
        vis[source]=1;
        for(auto child:adj[source]){
            if(vis[child]&& child==parent) continue;
            if(vis[child]) return true;
            if(solve(child,vis,adj,source)) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(solve(i,vis,adj,-1)) return true;
            }
        }
        return false;
    }
};