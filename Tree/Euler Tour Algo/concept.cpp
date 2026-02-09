
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 100001;
int values[N];
vector<int> g[N];

int in[N], out[N];
int t = 1;

int eul[2 * N + 5]; // used to find sum of path value between two node, we are storing negative value during (out) because it will nullify those value which are not part of path

int pref[2 * N + 5];  // use to find sum of value of subtree at that node, just store only (in) value 

// if we have to update value of node then find just add value at that node and make prefix sum so all child value will be updated
// if we have given query ? x y add value to each node which are not subtree of node x, there are lot of query and at the end it is asked find sum of subtree of all node, then just do =>         eul[in[x]-1] = -x, eul[in[x]] = x, eul[out[x]+1] = x and make prefix sum and find the value
void dfs(int node, int pp) {
    eul[t] = values[node];
    pref[t] = values[node];
    in[node] = t++;
    
    for (auto& v : g[node]) {
        if (v == pp) continue;
        dfs(v, node);
    }
    
    eul[t] = -values[node];
    // pref[t] = values[node];
    
    out[node] = t++;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b, w;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }
    // assuming tree is rooted at 1
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << in[i] << " " << out[i] << endl;
    }

    // checking node x is ancestor or not

    int u, v, x;
    cin >> u >> v >> x;

    if (in[x] < in[u] && out[x] > out[u]) {
        cout << "x is ancestor of u" << endl;
    } else if(in[u] < in[x] and out[x] < out[u]) {
        cout << "u is ancestor of x" << endl;
    }
    
    if (in[x] < in[v] && out[x] > out[v]) {
        cout << "x is ancestor of v" << endl;
    } else if(in[v] < in[x] and out[x] < out[v]) {
        cout << "v is ancestor of x" << endl;
    }

    // prefixSum
    int prev = 0;
    for (int i = 1; i <= 2 * n; i++) {
        eul[i] += prev;
        prev = eul[i];
    }

    for (int i = 1; i <= 2 * n; i++) {
        cout << eul[i] << " ";
    }
    
    cout << endl;
    
    int w, z;
    cin >> w >> z;
    cout << "sum of path beween " << w << " and " << z << " : ";
    cout << eul[in[z]] - eul[in[w] -1] << endl; // w is ancester of z
    

    // prev = 0;
    for (int i = 1; i <= 2*n; i++) {
        pref[i] += pref[i-1];
    }

    // sum of subtree
    for (int i = 1; i <= n; i++) {
        cout << "subtree sum of node " << i << " : ";
        cout << pref[out[i]]-pref[in[i]-1] << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}


// 7
// 1 2
// 1 3
// 2 4
// 2 5
// 3 6
// 3 7
// 10 11 12 13 14 15 16
// 1 2 3
// 3 7