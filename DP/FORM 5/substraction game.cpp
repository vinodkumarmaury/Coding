#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

ll n;
vector<ll> dp;

int rec(int x){
    if(x==0){
        return 0;
    }
    if(dp[x]!=-1){
        return dp[x];
    }
    int ans = 0;
    for(int m = 0;(1<<m)<=x;m++){
      if(rec(x-(1<<m))==0){
        ans = 1;
        break;
      }
    }
    return dp[x] = ans;
}

void solve(){
cin>>n;
dp.assign(n+1,-1);
for(int i = 0;i<=n;i++){
    cout<<i<<" "<<rec(i)<<endl;
}
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