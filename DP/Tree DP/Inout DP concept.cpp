#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1e5+5;
vector<int> g[N];
int indp[N];
int outdp[N];
int ans[N];

void dfs_in(int node,int pp){
    indp[node] = 0;
    for(auto &v:g[node]){
      if(v!=pp){
        dfs_in(v,node);
        indp[node] = max(indp[v]+1,indp[node]);
      }
    }
}

void dfs_out(int node,int pp,int outVal){
    outdp[node] = outVal;
    int max1 = -1,max2 = -1;
    for(auto &v:g[node]){
        if(v!=pp){
            if(indp[v]>max1){
                max2 = max1;
                max1 = indp[v];
            }
            else{
                max2 = max(max2,indp[v]);
            }
        }
    }

    for(auto &v:g[node]){
        if(v!=pp){
            if(indp[v]==max1){
                dfs_out(v,node,max(max2+2,outdp[node]+1));
            }
            else{
                dfs_out(v,node,max(max1+2,outdp[node]+1));
            }
        }
    }

}

void solve(){
int n;
cin>>n;

for(int i = 0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}

dfs_in(1,0);

dfs_out(1,0,0);

for(int i = 1;i<=n;i++){
    ans[i] = max(indp[i],outdp[i]);
    cout<<ans[i]<<" ";
}
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