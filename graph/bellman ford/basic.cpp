#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
const long long INF = 1e18;
using state = pair<int,pair<int,long long>>; 
// (u, (v, w))
#define F first
#define S second

vector<state> edges;
vector<long long> dist;
int n, m;

bool Bellman(int src) {
    dist[src] = 0;

    // Relax edges (n-1) times
    for(int i = 1; i <= n-1; i++) {
        bool changed = false;
        for(auto &e : edges) {
            int u = e.F;
            int v = e.S.F;
            long long w = e.S.S;
            if(dist[u] < INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                changed = true;
            }
        }
        if(!changed) break; // no update => stop early
    }

    // Negative cycle detection
    for(auto &e : edges) {
        int u = e.F;
        int v = e.S.F;
        long long w = e.S.S;
        if(dist[u] < INF && dist[v] > dist[u] + w) {
            return false; // negative cycle exists
        }
    }

    return true;
//  After the first n-1 relaxations, all shortest distances without negative cycles will have stabilized.

// If, in another round, a distance dist[v] still improves, it means v is affected by a negative cycle.

// To propagate this information (i.e., mark all vertices that are part of or reachable from a negative cycle), you can keep relaxing repeatedly. In practice, you do another n-1 passes: every update marks that vertex as being inside or reachable from a negative cycle.
}

void solve() {
    cin >> n >> m;
    edges.clear();
    dist.assign(n+1, INF);

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, {b, c}});
        // if graph is undirected:
        // edges.push_back({b, {a, c}});
    }

    if(Bellman(0)) {
        if(dist[n-1] == INF) cout << -1 << endl; // unreachable
        else cout << dist[n-1] << endl;
    } else {
        cout << "Negative cycle detected" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
