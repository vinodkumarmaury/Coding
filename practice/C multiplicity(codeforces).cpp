#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

int n;
vector<int> arr;
map<pair<int,int>, int> dp; // memoization map

int rec(int level, int len) {
    if (level == n)
        return (len > 0);

    auto key = make_pair(level, len);
    if (dp.count(key))
        return dp[key];

    int ans = 0;

    // Option 1: skip current element
    ans = (ans + rec(level + 1, len)) % MOD;

    // Option 2: include current element (if valid)
    if (arr[level] % (len + 1) == 0)
        ans = (ans + rec(level + 1, len + 1)) % MOD;

    return dp[key] = ans;
}

void solve() {
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dp.clear();
    cout << rec(0, 0) % MOD << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
