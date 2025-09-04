// https://www.codechef.com/problems/SCF
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n,m;
vector<vector<int>> g, grev;
vector<int> tout_order, vis, scc_num, type_;
int curr_scc = 0;

void dfs1(int node){
    vis[node] = 1;
    for(auto &v:g[node]){
        if(!vis[v]) dfs1(v);
    }
    tout_order.push_back(node);
}
void dfs2(int node){
    vis[node] = 1;
    scc_num[node] = curr_scc;
    for(auto &v:grev[node]){
        if(!vis[v]) dfs2(v);
    }
}

void solve(){
    cin >> n >> m;

    type_.assign(n+1, 0);
    for(int i=1;i<=n;i++) cin >> type_[i];

    g.assign(n+1, {});
    grev.assign(n+1, {});
    vis.assign(n+1, 0);
    scc_num.assign(n+1, 0);
    tout_order.clear();
    curr_scc = 0;

    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        // Only keep edges between non-cheap restaurants
        if(type_[a]==1 && type_[b]==1){
            g[a].push_back(b);
            grev[b].push_back(a);
        }
    }

    // First pass only over non-cheap nodes
    for(int i=1;i<=n;i++){
        if(type_[i]==1 && !vis[i]) dfs1(i);
    }

    reverse(tout_order.begin(), tout_order.end());
    vis.assign(n+1, 0);

    // Second pass on non-cheap nodes in reverse finishing order
    for(auto &x : tout_order){
        if(!vis[x]){
            curr_scc++;
            dfs2(x);
        }
    }

    // Condensation graph among non-cheap SCCs
    vector<set<int>> condensed_graph(curr_scc+1);
    vector<int> indeg(curr_scc+1, 0), outdeg(curr_scc+1, 0);

    for(int u=1; u<=n; u++){
        if(type_[u]==1){
            for(auto &v : g[u]){
                if(scc_num[u]!=scc_num[v]){
                    if(condensed_graph[scc_num[u]].insert(scc_num[v]).second){
                        indeg[scc_num[v]]++;
                        outdeg[scc_num[u]]++;
                    }
                }
            }
        }
    }

    int sources = 0, sinks = 0;
    if(curr_scc==0){
        // Shouldn't happen (problem guarantees at least one non-cheap)
        sources = sinks = 0;
    }else if(curr_scc==1){
        sources = sinks = 0; // already strongly connected
    }else{
        for(int i=1;i<=curr_scc;i++){
            if(indeg[i]==0) sources++;
            if(outdeg[i]==0) sinks++;
        }
    }

    int cheap = 0;
    for(int i=1;i<=n;i++) if(type_[i]==0) cheap++;

    int add_good = (curr_scc<=1 ? 0 : max(sources, sinks));
    int ans = add_good + cheap;
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
