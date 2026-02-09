#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

vector<vector<int>> adj;
vector<int> vis;
vector<int> par;
bool isFound = false;
void dfs(int node,int parrent){
     vis[node] = 1;
     for(auto &v:adj[node]){
          if(vis[v]&&v!=node){
               par[v] = node;
               isFound = true;
               return;
          }
          else if(!vis[v]){
               par[v] = node;
               dfs(v,node);
          }
     }
}

void solve(){
int v,e;
cin>>v>>e;
adj.resize(v+1);
par.resize(v+1,-1);

for(int i = 0;i<e;i++){
int a,b;
cin>>a>>b;
adj[a].push_back(b);
adj[b].push_back(a);
}
int lastnode = 0;
for(int i = 1;i<=v;i++){
     if(isFound)break;
     lastnode = i;
     vis.resize(v+1,0);
     dfs(i,-1);
}

if(!isFound){
     cout<<"IMPOSSIBLE"<<endl;
     return;
}

while(par[lastnode]!=-1){
     int x = par[lastnode];
     cout<<x<<" "<<lastnode<<endl;
     lastnode = x;
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