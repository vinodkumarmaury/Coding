#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e18;
ll n, m;
using state = pair<ll, pair<ll, ll>>;
vector<state> g;
vector<ll> dist, parent;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        g.push_back({a, {b, c}});
    }

    dist.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    ll x = -1;
    for (ll i = 1; i <= n; i++) {
        x = -1;
        for (auto &edge : g) {
            ll u = edge.first;
            ll v = edge.second.first;
            ll w = edge.second.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = max(-inf, dist[u] + w);
                parent[v] = u;
                x = v;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) x = parent[x];

    vector<ll> cycle;
    for (ll v = x;; v = parent[v]) {
        cycle.push_back(v);
        if (v == x && cycle.size() > 1) break;
    }
    reverse(cycle.begin(), cycle.end());

    for (auto &v : cycle) cout << v << " ";
    cout << "\n";

    return 0;
}
