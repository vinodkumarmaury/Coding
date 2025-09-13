#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

ll n;
vector<ll> arr;
vector<vector<ll>> dp;

ll rec(ll l,ll r){
  if(l>r){
    return 0;
  }
  if(dp[l][r]!=-1){
    return dp[l][r];
  }
  ll ans = max(arr[l]-rec(l+1,r),arr[r]-rec(l,r-1));
  return dp[l][r] = ans;
}

void solve(){
cin>>n;
arr.assign(n,0);
dp.assign(n+1,vector<ll>(n+1,-1));
for(ll i = 0;i<n;i++){
    cin>>arr[i];
}
cout<<rec(0,n-1)<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}