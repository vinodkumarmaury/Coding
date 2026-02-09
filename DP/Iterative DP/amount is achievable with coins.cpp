#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n,money;
vector<int> coins;

vector<vector<int>> dp;
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.assign(n+1,vector<int>(amount+1,-1));
        for(int i = n;i>=0;i--){
            for(int j = 0;j<=amount;j++){
                if(i==n){
                    if(j==0){
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = 0;
                    }
                    continue;
                }
                //
                dp[i][j] = 0;
                if(dp[i+1][j]){
                  dp[i][j] = 1;
                }
                if(coins[i]<=j&&dp[i][j-coins[i]]){
                    dp[i][j] = 1;
                }
            }
        }
        return dp[0][amount];
    }

void solve(){
cin>>n>>money;
coins.assign(n,0);
for(int i = 0;i<n;i++){
    cin>>coins[i];
}
cout<<coinChange(coins,money)<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}