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
    int maxchld = 1;
    for(int i = 2;i<=n;i++){
        if(dep[i]>dep[maxchld]){
            maxchld = i;
        }
    }
    dfs(maxchld,0,0);
    maxchld = 1;
    for(int i = 2;i<=n;i++){
        if(dep[i]>dep[maxchld]){
            maxchld = i;
        }
    }
    cout<<dep[maxchld]<<endl;
}




