#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
// You’re given a tree with ( n ) nodes, where each edge represents a unit distance between two connected nodes. The distance between any two nodes ( u ) and ( v ), denoted as ( d(u, v) ), is defined as the number of edges in the unique path connecting them. Your task is to calculate the total sum of distances for all possible pairs of nodes in the tree — in other words, find the sum of ( d(u, v) ) for every pair ((u, v)) such that ( 1  u <= v<= n ).

const int maxN = 2*1e5+5;

vector<int> g[maxN];
vector<ll> subTree;

void dfs(int node, int parent){
    subTree[node] = 1;
for(auto &v:g[node]){
    if(v!=parent){
        dfs(v,node);
        subTree[node]+=subTree[v];
    }
}
}

void solve(){
int n;
cin>>n;
subTree.assign(n+1,0);
for(int i = 0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}
dfs(1,0);

ll dist = 0;
for (int u = 0; u < n; u++) {
    for (auto v : g[u]) {
        if (subTree[v] < subTree[u]) { // v is child
            dist += subTree[v] * (n - subTree[v]);
        }
    }
}
cout<<dist<<endl;
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