#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 100100;
vector<int> g[N];
int values[N];
int dep[N];
int pref[N];
vector<vector<int>> par;

void dfs_partial_sum(int node,int pp){
    for(auto &v:g[node]){
        if(v!=pp){
            dfs_partial_sum(v,node);
        }
    }
    values[node]+=values[pp];
}


void dfs(int node,int pp){
dep[node] = dep[pp]+1;
par[node][0] = pp;
for(int i = 1;i<=20;i++){
    if(par[node][i-1]!=0){
        par[node][i] = par[par[node][i-1]][i-1];
    }
}

for(auto &v:g[node]){
    if(v!=pp)
    dfs(v,node);
}

}

int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    for(int i = 20;i>=0;i--){
        if((dep[x]-dep[y])&(1<<i)){
            x = par[x][i];
        }
    }
    if(x==y)return x;
    for(int i = 20;i>=0;i--){
        if(par[x][i]!=par[y][i]){
        x = par[x][i];
        y = par[y][i];
        }
    }
    return par[x][0];
}

void solve(){
int n,q;
cin>>n>>q;
par.assign(n+1,vector<int>(21,0));
for(int i = 1;i<=n;i++)cin>>values[i];
for(int i = 0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}
dep[0] = -1;
dfs(1,0);

while(q--){
    int x,y,z;
    cin>>x>>y>>z;
    values[x]+=z;
    values[y]+=z;
    int a = lca(x,y);
    values[a]-=z;
    values[par[a][0]]-=z;
}

dfs_partial_sum(1,0);

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}