#include <bits/stdc++.h>
using namespace std;

void helper(int n, int level, int arr[], vector<vector<int>> &perms) {
    if (level == n) {
        vector<int> perm(arr, arr + n);
        perms.push_back(perm);
        return;
    }

    unordered_set<int> used; 
    for (int i = level; i < n; i++) {
        if (used.count(arr[i])) continue;
        used.insert(arr[i]);

        swap(arr[level], arr[i]);
        helper(n, level + 1, arr, perms);
        swap(arr[level], arr[i]); 
    }
}

void solve() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n); 
    vector<vector<int>> perms;

    helper(n, 0, arr, perms);

    sort(perms.begin(), perms.end()); 

    for (auto &p : perms) {
        for (int x : p) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}