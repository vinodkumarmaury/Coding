#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n,m;
string s1,s2;
vector<vector<int>> dp;

int rec(int i,int j){
    if(i>=n||j>=m){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
  
 int ans =  rec(i+1,j);
 ans = max(ans,rec(i,j+1));
 if(s1[i]==s2[j]){
    ans = max(ans,1+rec(i+1,j+1));
 }
 return dp[i][j] = ans;
}

void solve(){
cin>>s1>>s2;
n = s1.length();
m = s2.length();
dp.assign(n+1,vector<int>(m+1,-1));
cout<<rec(0,0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}