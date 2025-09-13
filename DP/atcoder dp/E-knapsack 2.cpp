#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
const ll inf = 1e18;
using state = pair<ll,ll>;


vector<state> mat;
ll n,w;
vector<vector<ll>> dp; // level, weight
ll sum_val;

ll rec(ll level,ll leftVal){
    //recursion
    if(leftVal==0)return 0;
    if(level==n){
       return inf;
    }
    // cache; 
    if(dp[level][leftVal]!=-1){
        return dp[level][leftVal];
    }
   
   // transition
   ll ans = rec(level+1,leftVal);
   if(leftVal>=mat[level].second){
   ans = min(ans,mat[level].first+rec(level+1,leftVal-mat[level].second));
   }
   
   // save and return 

   return dp[level][leftVal] = ans;

}

void solve(){
cin>>n>>w;
mat.resize(n);
sum_val = 0;
for(ll i = 0;i<n;i++){
    ll a,b;
    cin>>a>>b;
    mat[i] = {a,b};
     sum_val+=b;
}
dp.resize(n+1,vector<ll>(sum_val+1,-1));

ll ans = 0;
for(int i = 0;i<=sum_val;i++){
    if(rec(0,i)<=w){
        ans = i;
    }
}
cout<<ans<<endl;
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