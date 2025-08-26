#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g;

vector<int> vis;
vector<int> color;
bool is_bipartite = 1;

void dfs(int node,int col){
    vis[node]=1;
    color[node]=col;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,(1+2)-col);
        }else if(color[node]==color[v]){
            is_bipartite = 0;
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1);
    color.resize(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,1);
        }
    }
    if(is_bipartite){
        cout<<"Possible\n";
        for(auto v:color)cout<<v<<" ";cout<<endl;
    }else{
        cout<<"Not possible\n";
    }

    // for(int i=1;i<=n;i++){
    //     cout<<comp_size[comp_num[i]]<<endl;
    // }

    // for(auto v:comp_num)cout<<v<<" ";cout<<endl;
    // for(auto v:comp_size)cout<<v<<" ";cout<<endl;
    // dfs(1);
    // for(auto v:vis)cout<<v<<" ";cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}