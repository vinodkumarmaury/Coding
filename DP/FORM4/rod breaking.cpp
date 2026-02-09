#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n;
vector<int> rod_breaking_point;
vector<vector<int>> dp;

int rec(int l,int r){
    // pruning

    // base case
     if(l+1==r){
        return 0;
     }
    // cache check
     if(dp[l][r]!=-1){
        return dp[l][r];
     }
    // compute
      int ans = 1e9;
      for(int p = l+1;p<=r-1;p++){
        ans = min(ans,rod_breaking_point[r]-rod_breaking_point[l]+rec(l,p)+rec(p,r));
      }
    // save and return
    return dp[l][r] = ans;
}

void solve(){
cin>>n;
rod_breaking_point.assign(n+1,0);
dp.assign(n+1,vector<int>(n+1,-1));
for(int i = 1;i<=n;i++){
    cin>>rod_breaking_point[i];
}
cout<<rec(0,n)<<endl;
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