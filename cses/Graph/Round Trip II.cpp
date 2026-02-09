#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<vector<int>> g;
vector<int> col,par,path;
bool isCycle = false;

void dfs(int node,int parrent){
  par[node] = parrent;
  col[node] = 2;
  for(auto &v:g[node]){
    if(v==parrent)continue;
    if(col[v]==1&&!isCycle){
      dfs(v,node);
      if (isCycle) return;
    }
    else if(col[v]==2&&!isCycle){
      isCycle = true;
      int curr = node;
      path.push_back(v);
      while(curr!=v){
        path.push_back(curr);
        curr = par[curr];
      }
      path.push_back(v);
      return;
    }
    else if(col[v]==3){
      // cross edges
    }
  }
  col[node] = 3;
}

int main(){
  int n,m;
  cin>>n>>m;
  g.resize(n+1);
  for(int i = 0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
  }
  par.assign(n+1,0);
  col.assign(n+1,1);
  for(int i = 1;i<=n;i++){
    if(col[i]==1&&!isCycle){
      dfs(i,0);
    }
  }
  if(!isCycle){
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
  }
  cout<<path.size()<<endl;
  for(auto &x:path){
    cout<<x<<" ";
  }
  cout<<endl;
}




