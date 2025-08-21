class Solution {
public:
    
    // bool comp(const pair<int,int> &a,const pair<int,int> &b){
    //     if(a.first==b.first){
    //         return a.second>b.second;
    //     }
    //     return a.first>b.first;
    // }
    
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int,int>> sum;
        for(int i = 0;i<aliceValues.size();i++){
            sum.push_back({aliceValues[i]+bobValues[i],i});
        }
        sort(sum.rbegin(),sum.rend());
        long long aliceScore = 0;
        long long bobScore = 0;
        long long aliceScore1 = 0;
        long long bobScore1 = 0;
        
        for(int i = 0;i<sum.size();i++){
            int idx = sum[i].second;
            if(i%2==0){
            aliceScore+=aliceValues[idx];
            bobScore1+=bobValues[idx];
            }
            else{
            aliceScore1+=aliceValues[idx];
            bobScore+=bobValues[idx];  
            }
        }
        if(aliceScore>bobScore)return 1;
        if(aliceScore1>bobScore1)return 1;
        if(aliceScore1==bobScore1||aliceScore==bobScore)return 0;
        return -1;
    }
};