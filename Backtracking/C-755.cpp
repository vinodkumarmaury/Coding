#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

void helper(int n, int &count, string s, long long val) {
    if (val > n) return;

    if (!s.empty()) {
        bool three = false, five = false, seven = false;
        for (char c : s) {
            if (c == '3') three = true;
            else if (c == '5') five = true;
            else if (c == '7') seven = true;
        }
        if (three && five && seven) count++;
    }

    // try adding 3
    helper(n, count, s + "3", val * 10 + 3);
    // try adding 5
    helper(n, count, s + "5", val * 10 + 5);
    // try adding 7
    helper(n, count, s + "7", val * 10 + 7);
}

void solve() {
    int n;
    cin >> n;
    int count = 0;
    helper(n, count, "", 0);
    cout << count << "\n";
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}