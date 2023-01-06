class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int count=0;
        for(auto bars:costs){
            if(bars<=coins){
                count++;
                coins-=bars;
            }
        }
        return count;
    }
};
