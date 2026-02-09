#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
// Here for each node value is given, we have to maximize absolute difference value between it's ancestor so we choose min or max value that will give max value
const int maxN = 2*1e5+5;

vector<int> g[maxN];
int value[maxN];
int ans[maxN];

void dfs(int node, int parent,int mini,int maxi){
ans[node] = max(abs(ans[node]-mini),abs(ans[node]-maxi));
for(auto &v:g[node]){
    if(v!=parent)
    dfs(v,node,min(mini,value[node]),max(maxi,value[node]));
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
for(int i = 0;i<n;i++){
    cin>>value[i];
}
dfs(0,-1,value[0],value[0]);
for(int i = 0;i<n;i++){
    cout<<ans[i]<<" ";
}
cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}