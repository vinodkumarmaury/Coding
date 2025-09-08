#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

string s1,s2;
int n1,n2;
vector<vector<int>> dp;

int rec(int i,int j){
  if(i==n1||j==n2){
    return 0;
  }
  if(dp[i][j]!=-1){
    return dp[i][j];
  }
  int ans = rec(i+1,j);
  ans = max(ans,rec(i,j+1));
  if(s1[i]==s2[j]){
    ans = max(ans,1+rec(i+1,j+1));
  }
  return dp[i][j] = ans;
}

string ans = "";
void generate(int i,int j){
    if(i==n1 || j==n2) return;

    if(s1[i] == s2[j]) {
        ans += s1[i];
        generate(i+1, j+1);
    } else {
        if(rec(i+1,j) >= rec(i,j+1)) {
            generate(i+1, j);
        } else {
            generate(i, j+1);
        }
    }
}


void solve() {
    cin>>s1>>s2;
    n1 = s1.length();
    n2 = s2.length();
    dp.assign(n1+1,vector<int>(n2+1,-1));
    rec(0,0);
    generate(0,0);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
