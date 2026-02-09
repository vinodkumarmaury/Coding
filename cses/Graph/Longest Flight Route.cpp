#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
vector<int> vis;
vector<vector<int>> g;

int maxDepth = 0;
void dfs(int node,int depth){
     vis[node] = 1;
     for(auto &v:g[node]){
          dfs(v,depth+1);
     }
}

void solve(){
int n,m;
cin>>n>>m;
vis.assign(n+1,0);
g.resize(n+1);
for(int i = 0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
}

for(int i = 1;i<=n;i++){
     if(!vis[i]){
          dfs(n,1);
     }
}

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}