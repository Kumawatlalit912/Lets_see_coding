class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<pair<int,int>>graph[n];
        for(auto i:flights){
            graph[i[0]].push_back({i[1],i[2]});
        }
        
        set<pair<int,pair<int,int>>>s;
        const int INF=1e9+7;
        vector<int>dist(n,INF);
        s.insert({0,{src,0}});
        dist[src]=0;
        while(!s.empty()){
            auto value=*s.begin();
            int node=value.second.first;
            int stops=value.first;
            int p=value.second.second;
            s.erase(value);
            if(stops>K) continue;
            for(auto child:graph[node]){
                int newnode=child.first;
                int price=child.second;
                
                if(stops<=K && price+p<dist[newnode]){
                    dist[newnode]=price+p;
                    s.insert({stops+1,{newnode,price+p}});
                }
            }
        }
        if(dist[dst]==INF) return -1;
        return dist[dst];
        
    }
};