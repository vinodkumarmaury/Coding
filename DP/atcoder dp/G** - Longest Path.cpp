#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
int n,m;
vector<vector<int>> g;
vector<int> dp;

int dfs(int node){
  if(dp[node]!=-1)return dp[node];
  int ans = 0;
  for(auto &v:g[node]){
      ans = max(ans,dfs(v)+1);
  }
 return dp[node] = ans;
}

int main(){
  cin>>n>>m;
  g.resize(n+1);
  dp.assign(n+1,-1);
  for(int i = 0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
  }
  int ans = 0;
  for(int i = 1;i<=n;i++){
    ans = max(ans,dfs(i));
  }
  cout<<ans<<endl;
  return 0;
}