#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
const ll inf = -1e18;
using state = pair<ll,ll>;


vector<state> mat;
ll n,w;
vector<vector<ll>> dp; // level, weight

ll rec(ll level,ll leftW){
    //recursion
    if(level==n){
       return 0;
    }
    // chache;
    if(dp[level][leftW]!=-1){
        return dp[level][leftW];
    }
   
   // transition
   ll ans = rec(level+1,leftW);
   if(leftW>=mat[level].first){
   ans = max(ans,mat[level].second+rec(level+1,leftW-mat[level].first));
   }
   
   // save and return 

   return dp[level][leftW] = ans;

}

void solve(){
cin>>n>>w;
mat.resize(n);
dp.resize(n+1,vector<ll>(w+1,-1));
for(ll i = 0;i<n;i++){
    ll a,b;
    cin>>a>>b;
    mat[i] = {a,b};
}

cout<<rec(0,w)<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}