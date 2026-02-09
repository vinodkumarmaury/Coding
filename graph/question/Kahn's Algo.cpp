#include<bits/stdc++.h>
using namespace std;


int n,m;
vector<vector<int>> adj;
vector<int> indeg;
vector<int> topo;
// vector<int> outdeg;

void kahn(){
queue<int> q;
for(int i = 1;i<=n;i++){
  if(indeg[i]==0)q.push(i);
}

while(!q.empty()){
  int node = q.front();
  q.pop();
  topo.push_back(node);
  for(auto &v:adj[node]){
    indeg[v]--;
    if(indeg[v]==0){
      q.push(v);
    }
  }
}

}

void solve(){
cin>>n>>m;
adj.assign(n+1,{});
indeg.assign(n+1,0);
for(int i = 0;i<m;i++){
  int a,b;
  cin>>a>>b;
  adj[a].push_back(b);
  indeg[b]++;
  // outdeg[a]++;
}

kahn();

for(auto &num:topo){
  cout<<num<<" ";
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