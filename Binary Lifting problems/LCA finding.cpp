#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

//  We have to find lowest common ancestor, three nodes are given x,y,z, where tree is rooted at z

vector<vector<int>> g;
int n;
vector<int> dep;
vector<vector<int>> par;

void dfs(int node,int pp){
dep[node] = dep[pp]+1;
par[node][0] = pp;

for(int i = 1;i<=20;i++){
    if(par[node][i-1]!=0){
     par[node][i] = par[par[node][i-1]][i-1];
    }  
}

for(auto &v:g[node]){
    if(v!=pp){
        dfs(v,node);
    }
}

}

int lca(int x,int y){
    if(dep[x]<dep[y]){
        swap(x,y);
    }

    for(int i = 20;i>=0;i--){
        if((dep[x]-dep[y])&(1<<i)){
           x =  par[x][i];
        }
    }

    if(x==y)return x;
    // try to bring x and y at same level
    for(int i = 20;i>=0;i--){
        if(par[x][i]!=par[y][i]){
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}

void solve(){
cin>>n;
g.assign(n+1,vector<int>());
dep.assign(n+1,0);
par.assign(n+1,vector<int>(21,0));
for(int i = 0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}
dep[0] = -1;
dfs(1,0);

int q;
cin>>q;
while(q--){
    int x,y,z;
    cin>>x>>y>>z;

    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5
// Take x=4, y=5, z=3.
// lca(x,y) = lca(4,5) = 2
// lca(y,z) = lca(5,3) = 1
// lca(x,z) = lca(4,3) = 1

    int a = lca(x,y),b = lca(y,z),c = lca(x,z); // to check lowest common anncestor
    if(a==b)cout<<c<<endl; // 
    else if(a==c)cout<<b<<endl;
    else cout<<a<<endl;
}
}

signed main(){
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