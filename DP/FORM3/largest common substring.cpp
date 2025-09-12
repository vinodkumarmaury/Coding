#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

ll n,m;
string s1,s2;
vector<vector<ll>> dp;
ll rec(ll i,ll j){
    if(i>=n||j>=m){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
ll ans = 0;
 rec(i+1,j);
 rec(i,j+1);
 if(s1[i]==s2[j]){
    ans = max(ans,1+rec(i+1,j+1));
 }
 return dp[i][j] = ans;
}

void solve(){
cin>>s1>>s2;
n = s1.length();
m = s2.length();
dp.assign(n+1,vector<ll>(m+1,-1));
rec(0,0);
ll max_len = 0;
for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
        max_len = max(max_len,dp[i][j]);
    }
}
cout<<max_len<<endl;
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