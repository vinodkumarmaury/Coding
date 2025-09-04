#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n,m;
vector<vector<int>> g;
vector<vector<int>> grev;
vector<int> tout_order;
vector<int> vis;
int curr_scc = 0;
vector<int> scc_num;


void dfs1(int node){
    vis[node] = 1;
    for(auto &v:g[node]){
        if(!vis[v]){
            dfs1(v);
        }
    }
    tout_order.push_back(node);
}

void dfs2(int node){
    vis[node] = 1;
    scc_num[node] = curr_scc;
    for(auto &v:grev[node]){
        if(!vis[v]){
            dfs2(v);
        }
    }
}

void solve(){
cin>>n>>m;
g.assign(n+1,{});
grev.assign(n+1,{});
vis.assign(n+1,0);
tout_order.clear();
scc_num.assign(n+1,0);
for(int i = 0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    grev[b].push_back(a);
}

for(int i = 1;i<=n;i++){
    if(!vis[i]){
        dfs1(i);
    }
}
reverse(tout_order.begin(),tout_order.end());
vis.assign(n+1,0);

for(auto &x:tout_order){
    if(!vis[x]){
        curr_scc++;
        dfs2(x);
    }
}

for(int i = 1;i<=n;i++){
    cout<<scc_num[i]<<" ";
}
cout<<endl;


// vector<vector<int>> condensed_graph;
vector<set<int>> condensed_graph(n+1);  // we are using 'set' to de-duplicate edges or parallel edges, it will be DAG because there will not cycle

for(int i = 1;i<=n;i++){
    for(auto &v:g[i]){
        if(scc_num[i]!=scc_num[v]){
            condensed_graph[scc_num[i]].insert(scc_num[v]);
        }
    }
}

for(int i = 1;i<=curr_scc;i++){
    cout<<"for"<<i<<"th scc: ";
    for(auto &node:condensed_graph[i]){
        cout<<node<<" ";
    }
    cout<<endl;
}

}

int main(){
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