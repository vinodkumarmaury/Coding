#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

vector<vector<int>> adj;
vector<int> vis;
vector<int> comp_no;
vector<int> comp_size;
vector<int> topo;

void dfs(int node){
  vis[node] = 1;
  for(auto v:adj[node]){
    if(!vis[v]){
      dfs(v);
    }
  }
  topo.push_back(node);
}



void solve(){
int v,e;
cin>>v>>e;
adj.resize(v+1);
vis.resize(v+1,0);
for(int i = 0;i<e;i++){
int a,b;
cin>>a>>b;
adj[a].push_back(b);
}

for(int i = 1;i<=v;i++){
  if(!vis[i]){
    dfs(i);
  }
}

int dp[v+1] = {-1};

int final = 0;
for(auto &node : topo){
  int ans = 1;
  for(auto &vv:adj[node]){
    ans = max(ans,1+dp[vv]);
  }
  dp[node] = ans;
  final = max(ans,final);
}
cout<<final<<endl;

reverse(topo.begin(),topo.end());
for(auto &node:topo){
  cout<<node<<" ";
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