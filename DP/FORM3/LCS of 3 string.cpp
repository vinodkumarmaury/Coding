#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n,m,k;
string s1,s2,s3;
vector<vector<vector<int>>> dp;

int rec(int i,int j,int w){
    if(i>=n||j>=m||w>=k){
        return 0;
    }
    if(dp[i][j][w]!=-1){
        return dp[i][j][w];
    }
  
 int ans =  rec(i+1,j,w);
 ans = max(ans,rec(i,j+1,w));
 ans = max(ans,rec(i,j,w+1));
 if(s1[i]==s2[j]&&s2[j]==s3[w]){
    ans = max(ans,1+rec(i+1,j+1,w+1));
 }
 return dp[i][j][w] = ans;
}

void solve(){
cin>>s1>>s2>>s3;
n = s1.length();
m = s2.length();
k = s3.length();
dp.assign(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
cout<<rec(0,0,0);
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