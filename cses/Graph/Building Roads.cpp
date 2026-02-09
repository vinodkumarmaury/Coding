#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;

void dfs(int node){
    vis[node] = 1;
    for(auto &v:g[node]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> roads;
    for(int i = 1;i<=n;i++){
      if(!vis[i]){
        dfs(i);
        roads.push_back(i);
      }
    }
    cout<<roads.size()-1<<endl;
    for(int i = 1;i<roads.size();i++){
        cout<<roads[i-1]<<" "<<roads[i]<<endl;
    }
}