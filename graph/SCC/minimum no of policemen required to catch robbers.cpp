#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<vector<int>> g,grev;
vector<int> tout_order,vis;
 int curr_scc = 0;
 vector<int>scc_num;

void dfs1(int node){
  vis[node] = 1;
  for(auto &v:g[node]){
    if(!vis[v]){
      dfs1(v);
    }
  }
  tout_order.push_back(node);
}

void dfs2(int node){
  vis[node] = 1;
  scc_num[node] = curr_scc;
  for(auto &v:grev[node]){
    if(!vis[v]){
      dfs2(v);
    }
  }
}

int main() 
{
    int n,m;
    cin>>n>>m;
    g.resize(n+1),grev.resize(n+1);
    for(int i = 0;i<m;i++){
      int a,b;
      cin>>a>>b;
      g[a].push_back(b);
      grev[b].push_back(a);
    }
    
    vis.assign(n+1,0);
    for(int i = 1;i<=n;i++){
      if(!vis[i]){
        dfs1(i);
      }
    }
    reverse(tout_order.begin(),tout_order.end());
    vis.assign(n+1,0);
    scc_num.assign(n+1,0);
    for(auto &x:tout_order){
      if(!vis[x]){
        curr_scc++;
        dfs2(x);
      }
    }
    vector<int> indegree(curr_scc+1,0);
    vector<set<int>> condensed_scc(curr_scc+1); // it's size will equal to no of curr_scc
    for(int i = 1;i<=n;i++){
      for(auto &v:g[i]){
        if (!condensed_scc[scc_num[i]].count(scc_num[v])) {
            condensed_scc[scc_num[i]].insert(scc_num[v]);
            indegree[scc_num[v]]++;
            }
      }
    }
    
    int ans = 0;
    for(int i = 1;i<=curr_scc;i++){
      if(indegree[i]==0)ans++;
    }
    cout<<ans<<endl;
    
    return 0;
}



