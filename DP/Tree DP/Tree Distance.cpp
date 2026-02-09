// https://maang.in/problems/Tree-Distance-449?resourceUrl=cs89-cp502-pl3751-rs449&returnUrl=%5B%22%2Fcourses%2FZero-to-Hero-in-Trees-89%3Ftab%3Dchapters%22%5D

// You are given a tree with `n` vertices and a positive integer `k`.
// Find the number of distinct pairs of vertices whose distance is exactly `k`.
// Note that pairs `(u, v)` and `(v, u)` are considered the same.

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

vector<vector<int>> g,dp;
int n,k;
int ans;

void dfs(int node,int pp){
    dp[node].assign(k+1,0);
    dp[node][0] = 1;
    for(auto &v:g[node]){
        if(v!=pp){
            dfs(v,node);
            ans+=dp[v][k-1];
            for(int i = 1;i<k;i++){
                ans+=dp[v][i-1]*dp[node][k-i];
            }
            for(int i = 0;i<k;i++){
                dp[node][i+1] +=dp[v][i];
            }
        }
    }
}

void solve(){
cin>>n>>k;
g.resize(n+1);
dp.resize(n+1);
ans = 0;
for(int i = 0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}

dfs(1,0);
cout<<ans<<endl;
g.clear();
dp.clear();
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