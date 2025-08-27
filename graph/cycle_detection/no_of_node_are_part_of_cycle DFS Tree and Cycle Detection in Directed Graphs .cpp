#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> adj;
vector<int> col,parent,prefix,cntCycle;
bool isCycle = false;
vector<int> path;

void dfs(int node,int par){
  col[node] = 2;
  parent[node] = par;
 for(auto &v:adj[node]){
  if(col[v]==1){
    dfs(v,node);
  }
  else if(col[v]==2){
    // there is cycle
    if(!isCycle){
    path.push_back(v);
    int curr = node;
    while(curr!=v){
      path.push_back(curr);
      curr = parent[curr];
    }
    }
    isCycle = true;
    cntCycle[node]++;
    cntCycle[parent[v]]--;
  }
  else if(col[v]==3){
    // cross edges
  }
 }
 col[node]  = 3; // it's all child explored
 prefix.push_back(node);
 
}

void solve(){
  cin>>n>>m;
  adj.assign(n+1,{});
  col.assign(n+1,1);
  parent.assign(n+1,0);
  cntCycle.assign(n+1,0);

  for(int i = 0;i<m;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
  }

 for(int i = 1;i<=n;i++){
 if(col[i]==1){
  dfs(i,0);
 }
 }
 if(isCycle){
  cout<<"Yes"<<endl;
 }
 else{
  cout<<"No"<<endl;
 }
 
reverse(path.begin(),path.end());

for(auto &num:path){
  cout<<num<<" ";
}
cout<<endl;
for(auto num : prefix){
    cntCycle[parent[num]]+=cntCycle[num];
}

int countNode = 0;
for(int i = 1;i<=n;i++){
    if(cntCycle[i]>0)countNode++;
}
cout<<countNode<<endl;
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