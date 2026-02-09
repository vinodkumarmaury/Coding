vector<vector<int>> dp;
const int inf = 1e9;
class Solution {
public:
   
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.assign(n+1,vector<int>(amount+1,-1));
        for(int i = n;i>=0;i--){
            for(int j = 0;j<=amount;j++){
                if(i==n){
                    if(j==0){
                        dp[i][j] = 0;
                    }
                    else{
                        dp[i][j] = inf;
                    }
                    continue;
                }
                //not take
                dp[i][j] = dp[i+1][j];
                if(coins[i]<=j){
                    dp[i][j] = min(dp[i][j],1+dp[i][j-coins[i]]);
                }
            }
        }
        return dp[0][amount]>=inf?-1:dp[0][amount];
    }
};