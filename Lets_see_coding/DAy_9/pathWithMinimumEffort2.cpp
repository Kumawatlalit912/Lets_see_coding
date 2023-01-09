using priority_queue
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n=heights.size();
        int m=heights[0].size();
        // set<pair<int,pair<int,int>>>s;
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>
        ,greater<pair<int,pair<int,int>>>>pq;
        const int INF=1e9+7;
        vector<vector<int>>dist(n,vector<int>(m,INF));
        // s.insert({0,{0,0}});
        dist[0][0]=0;
        //you always forgets this dist[0][0]=0;
        pq.push({0,{0,0}});
        int r[]={-1,0,1,0};
        int c[]={0,1,0,-1};
        
        while(!pq.empty()){
            // auto value=*s.begin();
            auto value=pq.top();
            int diff=value.first;
            int ro=value.second.first;
            int co=value.second.second;
            pq.pop();
            // s.erase(value);
            if(ro==n-1 && co==m-1) return diff;
            
            for(int i=0;i<4;i++){
                int newro=ro+r[i];
                int newco=co+c[i];
                if(newro>=0 && newco>=0 && newro<n && newco<m){
                    int newDiff=abs(heights[ro][co]-heights[newro][newco]);
                    int newEffort=max(newDiff,diff);
                    if(newEffort<dist[newro][newco]){
                        dist[newro][newco]=newEffort;
                        // s.insert({dist[newro][newco],{newro,newco}});
                        pq.push({newEffort,{newro,newco}});
                    }
                }
            }
        }
        return 0;
        
    }
};
