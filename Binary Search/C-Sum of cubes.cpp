#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

vector<ll> cubes(10010);

void precompute() {
    for (ll i = 1; i < 10010; i++) {
        cubes[i] = i * i * i;
    }
}

void solve() {
    ll x;
    cin >> x;
    ll low = 1, high = cbrt(x) + 1;

    while (low <= high) {
        ll sum = cubes[low] + cubes[high];
        if (sum == x) {
            cout << "YES" << endl;
            return;
        }
        else if (sum > x) {
            high--; 
        }
        else {
            low++; 
        }
    }

    cout << "NO" << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    precompute();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
