#include <bits/stdc++.h>
using namespace std;

using state = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<state> v;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({b, a});
    }

    sort(v.begin(), v.end());

    int ans = 1;
    int ending = v[0].first;

    for (int i = 1; i < n; i++) {
        if (ending <= v[i].second) {
            ans++;
            ending = v[i].first;
        }
    }

    cout << ans << endl;
    return 0;
}
