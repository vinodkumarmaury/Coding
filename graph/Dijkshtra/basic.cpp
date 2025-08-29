#include<bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
using state = pair<long long,int>;
#define F first
#define S second

int n,m;
vector<vector<state>> adj;
vector<long long> vis,dist;

void dijkshtra(){
priority_queue<state> pq;
dist[1] = 0;
pq.push({0,1}); // -dist, node

while(!pq.empty()){
  state curr = pq.top();
  pq.pop();
  if(vis[curr.S])continue;
  vis[curr.S] = 1;
  long long d = -curr.F;
  for(auto &node:adj[curr.S]){
    if(dist[node.S]>d+node.F){
      dist[node.S] = d+node.F;
      pq.push({-dist[node.S],node.S});
    }
  }
}

}

void solve(){
cin>>n>>m;
adj.assign(n+1,{});
dist.assign(n+1,inf);
vis.assign(n+1,0);

for(int i = 0;i<m;i++){
int a,b;
long long c;
cin>>a>>b>>c;
adj[a].push_back({c,b});
}

dijkshtra();

for(int i = 1;i<=n;i++){
  cout<<dist[i]<<" ";
}
cout<<endl;
}


int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int t=1;
while(t--){
  solve();
}
return 0;
}