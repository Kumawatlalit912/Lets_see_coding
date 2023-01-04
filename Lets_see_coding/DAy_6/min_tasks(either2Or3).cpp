minimum rounds to complete the tasks lc--> 2244

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>m;
        for(auto i:tasks){
            m[i]++;
        }
        int count=0;
        for(auto i:m){
            if(i.second==1) return -1;
            else if(i.second%3==0) count+=i.second/3;
            else{
                count+=i.second/3+1;
            }
        }
        return count;
    }
};