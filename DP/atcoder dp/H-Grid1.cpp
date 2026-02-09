#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;
int h,w;
vector<vector<char>>mat;
vector<vector<ll>> dp;

ll rec(int i,int j){
  if(i>=h||j>=w)return 0;
  if(i==h-1&&j==w-1)return 1;
  if(mat[i][j]=='#')return 0;
  if(dp[i][j]!=-1)return dp[i][j];
  ll ans = 0;
    ans = (ans+rec(i+1,j))%mod;
    ans = (ans+rec(i,j+1))%mod;
    return dp[i][j] = ans;
}

int main(){
  cin>>h>>w;
  mat.resize(h+1,vector<char>(w+1));
  dp.assign(h+1,vector<ll>(w+1,-1));
  for(int i = 0;i<h;i++){
    for(int j = 0;j<w;j++){
        cin>>mat[i][j];
    }
}
  cout<<rec(0,0)<<endl;
}