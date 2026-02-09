#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<vector<int>> g;
vector<int> dist,par;


void BFS(){
  queue<int> q;
  q.push(1);
  dist[1] = 0;
  par[1] = -1;
  while(!q.empty()){
    int node = q.front();
    q.pop();
    for(auto &v:g[node]){
      if(dist[v]>dist[node]+1){
        dist[v] = dist[node]+1;
        q.push(v);
        par[v] = node;
      }
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
    par.assign(n+1,-1);
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    dist.assign(n+1,1e9);
    
    BFS();
    if (dist[n] == 1e9) {
    cout << "IMPOSSIBLE\n";
    return 0;
}
    vector<int> path;
    int temp = n;
    while(temp!=-1){
        path.push_back(temp);
        temp = par[temp];
    }
    reverse(path.begin(),path.end());
    cout<<path.size()<<endl;
    for(auto &x:path){
        cout<<x<<" ";
    }
    
    
    cout<<endl;
    return 0;
}


