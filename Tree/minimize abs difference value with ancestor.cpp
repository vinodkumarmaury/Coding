#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
// Here for each node value is given, we have to minimze absolute difference value between it's ancestor, so we choose neighbour
const int maxN = 2*1e5+5;

vector<int> g[maxN];
int value[maxN];
int ans[maxN];
multiset<int> mt;

void insert(int x){
    mt.insert(x);
}

void remove(int x){
    mt.erase(mt.find(x));
}

int query(int x){
int ans = 1e9;
auto it = mt.lower_bound(x);
if(it!=mt.end()){
    ans = min(ans,abs(*it-x));
}
if(it!=mt.begin()){
    it--;
   ans = min(ans,abs(*it-x));
}
return ans;
}

void dfs(int node, int parent){
if(mt.empty()) ans[node] = 0;
else ans[node] = query(value[node]);
insert(value[node]);
for(auto &v:g[node]){
    if(v!=parent)
    dfs(v,node);
}
remove(value[node]);
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
dfs(0,-1);
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