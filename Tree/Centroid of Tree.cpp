#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

const int  maxN = 2*1e5+5;

vector<int> g[maxN];
vector<int> cnt,centroid;
int n;

void dfs(int node,int parent){
cnt[node] = 1;
bool is_centroid = true;
for(auto &v:g[node]){
    if(v!=parent){
    dfs(v,node);
    cnt[node]+=cnt[v];
    if(cnt[v]>n/2)is_centroid = false;  // if subtree size is greater than n/2;
    }
}
if(n-cnt[node]>n/2)is_centroid = false;  // it's parent size is grater than n/2;
if(is_centroid)centroid.push_back(node);
}




void solve(){
cin>>n;
for(int i = 0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}
cnt.assign(n+1,0);
dfs(1,-1);

sort(centroid.begin(),centroid.end());

cout<<centroid[0]<<endl;

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