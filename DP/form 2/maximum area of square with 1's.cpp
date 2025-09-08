#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

ll n,m;
vector<vector<ll>> mat;
vector<vector<ll>> dp;

ll rec(ll i,ll j){

    // pruning 
    if(i<0||j<0){
        return 0;
    }
    if(mat[i][j]==0)return 0;
    // base case
    if(i == 0 && j == 0) {
        return mat[i][j];
      }
    // cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    // compute
    ll ans =  rec(i-1,j)+mat[i][j];
    ans = min(ans,rec(i,j-1)+mat[i][j]);
    ans = min(ans,rec(i-1,j-1)+mat[i][j]);
    // save and return
    return dp[i][j] = ans;
}

void solve(){
cin>>n>>m;
mat.assign(n,vector<ll>(m));
dp.assign(n,vector<ll>(m,-1));

for(ll i = 0;i<n;i++){
    for(ll j = 0;j<m;j++){
        cin>>mat[i][j];
    }
}

ll maxSide = 0;
for(ll i = 0;i<n;i++){
    for(ll j = 0;j<m;j++){
        maxSide = max(maxSide,rec(i,j));
    }
}
cout<<maxSide*maxSide<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
