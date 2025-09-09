#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod  = 1e9+7;

string s1,s2;
int n,m;
vector<vector<int>> dp;
vector<vector<int>> back;

int rec(int i,int j){
  
  // prunning
  
  // base case
  if(i==n&&j==m){
    return 0;
  }
  // cache check
  if(dp[i][j]!=-1){
   return dp[i][j]; 
  }
  // compute
  int ans = 1e9;
  if(i<n){
    ans = min(ans,1+rec(i+1,j));
    back[i][j] = 0;
  }
  if(j<m){
    ans = min(ans,1+rec(i,j+1));
    back[i][j] = 1;
  }
  if(i<n&&j<m&&s1[i]==s2[j]){
    ans = min(ans,1+rec(i+1,j+1));
    back[i][j] = 2;
  }
  // save and return
  return dp[i][j] = ans;
}

// string ans;

void generate(int i,int j){
  if(i==n&&j==m)return;
  if(back[i][j]==0){
    cout<<"-"<<s1[i];
    generate(i+1,j);
  }
  else if(back[i][j]==1){
    cout<<"+"<<s2[j];
    generate(i,j+1);
  }
  else if(back[i][j]==2){
    cout<<s1[i];
    generate(i+1,j+1);
  }
}

void solve(){
  cin>>s1>>s2;
  n = s1.length();
  m = s2.length();
  dp.assign(n+1,vector<int>(m+1,-1));
  back.assign(n+1,vector<int>(m+1,-1));
  rec(0,0);
 cout<<rec(0,0)<<endl;
  generate(0,0);
  cout<<endl;
}

int main() 
{
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