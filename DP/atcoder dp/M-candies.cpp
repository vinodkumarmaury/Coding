#include<bits/stdc++.h> 
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

vector<vector<ll>> dp,pref;
vector<ll> arr;
int n,k;

ll rec(int level,int kLeft){
  if(kLeft < 0) return 0;
  if(level == n) return (kLeft == 0); 
  if(dp[level][kLeft]!=-1)return dp[level][kLeft];
  if (level + 1 <= n && pref[level + 1][0] == -1) {
        pref[level + 1][0] = rec(level + 1, 0);
        for (int j = 1; j <= k; j++)
        pref[level + 1][j] = (pref[level + 1][j - 1] + rec(level + 1, j)) % mod;
    }
    ll ans = pref[level + 1][kLeft];
    if (kLeft - arr[level] - 1 >= 0)
    ans = (ans - pref[level + 1][kLeft - arr[level] - 1] + mod) % mod;
  return dp[level][kLeft] = ans;
}

int main(){
  cin>>n>>k;
  dp.assign(n+1,vector<ll>(k+1,-1));
  pref.assign(n+1,vector<ll>(k+1,-1));
  arr.assign(n,0);
  for(int i = 0;i<n;i++)cin>>arr[i];
  cout<<rec(0,k)<<endl;
  return 0;
}