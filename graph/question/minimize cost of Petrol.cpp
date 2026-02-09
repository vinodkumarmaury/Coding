#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
const int inf = 1e9;
using ll = long long;
using state = pair<int,int>; // (node, petrol)

vector<vector<int>> dist, vis;
vector<vector<pair<int,int>>> adj; // adj[node] = { {next, distance} }
vector<int> petrolCostAtEachNode;

int n, m, k;

void Dijkstra(state st){
    priority_queue<pair<int,state>, vector<pair<int,state>>, greater<>> pq;
    pq.push({0, st}); // distance, {node, petrol}
    dist[st.first][st.second] = 0; //node, petrol

    while(!pq.empty()){
        auto [curr_dis, curr] = pq.top();
        pq.pop();
        int node = curr.first;
        int petrol = curr.second;

        if(vis[node][petrol]) continue;
        vis[node][petrol] = 1;

        for(auto &v : adj[node]){
            int new_node = v.first;
            int need = v.second;

            // Move if enough petrol
            if(petrol >= need){
                if(dist[new_node][petrol-need] > curr_dis){
                    dist[new_node][petrol-need] = curr_dis;
                    pq.push({dist[new_node][petrol-need], {new_node, petrol-need}});
                }
            }
        }

        // Option to buy more petrol at this node
        if(petrol+1 <= k){
            int cost = petrolCostAtEachNode[node];
            if(dist[node][petrol+1] > curr_dis + cost){
                dist[node][petrol+1] = curr_dis + cost;
                pq.push({dist[node][petrol+1], {node, petrol+1}});
            }
        }
    }
}

void solve(){
    cin >> n >> m >> k;
    adj.assign(n, {});
    petrolCostAtEachNode.resize(n);
    dist.assign(n, vector<int>(k+1, inf));
    vis.assign(n, vector<int>(k+1, 0));

    for(int i=0;i<m;i++){
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({b,d});
        adj[b].push_back({a,d}); // if bidirectional
    }

    for(int i=0;i<n;i++) cin >> petrolCostAtEachNode[i];

    int st = 0, ed = n-1;
    Dijkstra({st,0});

    int ans = inf;
    for(int p=0;p<=k;p++){
        ans = min(ans, dist[ed][p]);
    }

    if(ans==inf) cout << -1 << endl;
    else cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
