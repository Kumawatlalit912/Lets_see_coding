class Solution {
public:
bool solve(int source,vector<int>graph[],vector<int>&vis,stack<int>&s,vector<int>&mark){
    vis[source]=1;
    mark[source]=1;
    for(auto child:graph[source]){
        if(!vis[child]){
            if(solve(child,graph,vis,s,mark)) return true;
        }
        if(vis[child] && mark[child]) return true;
    }
    s.push(source);
    mark[source]=0;
    return false;
}
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int>vis(N,0);
	    vector<int>mark(N,0);
	    vector<int>graph[N];
	    int n=prerequisites.size();
	    stack<int>s;
	    for(int i=0;i<n;i++){
	        graph[prerequisites[i].first].push_back(prerequisites[i].second);
	    }
	    for(int i=0;i<N;i++){
	        if(!vis[i]){
	         if(solve(i,graph,vis,s,mark)) return false;   
	        }
	    }
	    if(s.size()==N) return true;
	    return false;
	}
};