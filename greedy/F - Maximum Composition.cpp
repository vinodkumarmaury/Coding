#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using state = pair<int,int>;  // (A,B)

bool comp(const state &x, const state &y) {
    return 1LL * x.second * (y.first - 1) > 1LL * y.second * (x.first - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<state> st(n);
    for (int i = 0; i < n; i++) {
        cin >> st[i].first >> st[i].second;  
    }

    sort(st.begin(), st.end(), comp);

    vector<ll> dp(k + 1, -1e18);
    dp[0] = 1;

    for (auto [A, B] : st) {
        for (int j = k - 1; j >= 0; --j) {
            if (dp[j] != -1e18) {
                dp[j + 1] = max(dp[j + 1], dp[j] * A + B);
            }
        }
    }

    cout << dp[k] << "\n";
    return 0;
}
