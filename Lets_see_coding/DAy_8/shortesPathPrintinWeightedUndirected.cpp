we can use priority queue,set for this 
  i have used set data structure(with pairs);

priority_queue<pair<int,int>,vector<pair<int,int>,greater<pair<int,int>>p; (i dont know its right or not syntactilly ,check out for clearity )





class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        // vector<int>store;
        vector<pair<int,int>>graph[n+1];
        for(auto edge:edges){
            graph[edge[0]].push_back({edge[1],edge[2]});
            graph[edge[1]].push_back({edge[0],edge[2]});
        }
        
        set<pair<int,int>>s;
        s.insert({0,1});
        const int INF=1e9+7;
        vector<int>dis(n+1,INF),parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        dis[1]=0;
        while(!s.empty()){
            auto f=*(s.begin());
            auto node=f.second;
          
            auto wei=f.first;
            s.erase(f);
            for(auto child:graph[node]){
                int nod=child.first;
                int dist=child.second;
                if(wei+dist<dis[nod]){
                    s.insert({wei+dist,nod});
                    dis[nod]=wei+dist;
                    parent[nod]=node;
                }
            }
            
        }
        if(dis[n]==INF) return {-1};
        int node=n;
        vector<int>path;
        while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(node);
        reverse(path.begin(),path.end());
        return path;
    }
};
