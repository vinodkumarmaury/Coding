#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int inf = 1e9;
using ll = long long;

string s;
int n;
vector<vector<int>> dp;

int rec(int l,int r){
  if(l>=r){
    return true;
  }
  if(dp[l][r]!=-1){
    return dp[l][r];
  }
  int ans = s[l]==s[r]&&rec(l+1,r-1);
  return dp[l][r] = ans;
}

void solve(){
  cin>>s;
  n = s.length();
  dp.assign(n+1,vector<int>(n+1,-1));
  rec(0,n-1);
  int q;
  cin>>q;
  while(q--){
    int l,r;
    cin>>l>>r;
    if(rec(l,r)){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
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