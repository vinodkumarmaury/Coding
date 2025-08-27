#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> adj;
vector<int> col;
bool isCycle = false;

void dfs(int node){
  col[node] = 2;
  
 for(auto &v:adj[node]){
  if(col[v]==1){
    dfs(v);
  }
  else if(col[v]==2){
    // there is cycle
    isCycle = true;
    return;
  }
  else if(col[v]==3){
    // cross edges
  }
 }
 col[node]  = 3; // it's all child explored
 
}

void solve(){
  cin>>n>>m;
  adj.assign(n+1,{});
  col.assign(n+1,1);

  for(int i = 0;i<m;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
  }

 for(int i = 1;i<=n;i++){
 if(col[i]==1&&!isCycle){
  dfs(i);
 }
 }
 if(isCycle){
  cout<<"Yes"<<endl;
 }
 else{
  cout<<"No"<<endl;
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