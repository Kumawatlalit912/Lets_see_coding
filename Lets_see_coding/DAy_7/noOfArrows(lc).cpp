class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // int n=points.size();
        // int noOfArrows=n;
        // set<pair<int,int>>s;
        // for(auto i:points){
        //     s.insert({i[0],i[1]});
        // }
        // int count=0;
        // sort(points.begin(),points.end());
        // for(int i=0;i<n;i++){
        //     if(s.count({points[i][0],points[i][1]})){
        //         noOfArrows--;
        //         count++;
        //         for(int j=i+1;j<n;j++){
        //             if(points[i][1]>=points[j][0]){
        //                 s.erase({points[j][0],points[j][1]});
        //             }
        //         }
        //     }
        // }
        // return count;

        int lastP=points[0][1];
        int ans=1;
        sort(begin(points),end(points));
        for(auto i:points){
            if(i[0]>lastP){
                ans++;
                lastP=i[1];
            }
            lastP=min(lastP,i[1]);
        }
            return ans;
    }

};