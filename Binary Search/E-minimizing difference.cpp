#include<bits/stdc++.h>
using namespace std;
#define int long long      // use 64-bit default
#define big __int128        // use "big" for 128-bit ops
#define endl '\n'

int n, k;
vector<int> a, pref;

big prefSum(int l, int r) {
    if (l > r) return 0;
    big res = pref[r];
    if (l) res -= pref[l - 1];
    return res;
}

bool check(int D) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && a[j] <= a[i] + D) j++;
        int last = j - 1;

        big leftCost = 0, rightCost = 0;
        if (i > 0)
            leftCost = (big)a[i] * i - prefSum(0, i - 1);
        if (last < n - 1) {
            big sumRight = prefSum(last + 1, n - 1);
            big want = (big)(a[i] + D) * (n - 1 - last);
            rightCost = sumRight - want;
        }

        if (leftCost + rightCost <= (big)k)
            return true;
    }
    return false;
}

void solve() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    pref.resize(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + a[i];

    int low = 0, high = a.back() - a.front();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (check(mid)) high = mid;
        else low = mid + 1;
    }
    cout << low << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
