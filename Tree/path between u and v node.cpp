#include<bits/stdc++.h>
using namespace std;
using ll  = long long;

vector<int> g[1000100];
int par[1000100];
int dep[1000100];

void dfs(int node, int parent,int depth){
    par[node] = parent;
    dep[node] = depth;

    for(auto &v:g[node]){
        if(v!=parent){
            dfs(v,node,depth+1);
        }
    }
    
}

vector<int> pathToroot(int x){
    vector<int> path;
    while(x!=0){
        path.push_back(x);
        x = par[x];
    }
    reverse(path.begin(),path.end());
    return path;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int u,v;
    cin>>u>>v;
    dfs(1,0,0);
   vector<int> pathU = pathToroot(u);
   vector<int> pathV = pathToroot(v);
   int lca = 1;
   int len = min(pathU.size(),pathV.size());
   for(int i = 0;i<len;i++){
    if(pathU[i]==pathV[i]){
        lca = pathU[i];
    }
    else break;
   }
   
  vector<int> result; 
  int x = u;
  while(x!=lca){
  result.push_back(x);
  x = par[x];
  }
  result.push_back(lca);
  vector<int> temp;
  x = v;
  while(x!=lca){
  temp.push_back(x);
  x = par[x];
  }
  reverse(temp.begin(),temp.end());
  for(auto &xx:temp){
    result.push_back(xx);
  }

for(auto &p:result){
    cout<<p<<" ";
}
cout<<endl;
   return 0;
}




