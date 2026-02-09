#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n,m;
vector<vector<int>> mat;
vector<vector<int>> dp;

int rec(int i,int j){

    // pruning 
    if(i<0||j<0){
        return -1e9;
    }
    // base case
    if(i == 0 && j == 0) {
    return mat[i][j];
    } 
    // chache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    // compute
    int ans =  rec(i-1,j)+mat[i][j];
    ans = max(ans,rec(i,j-1)+mat[i][j]);
    // save and return
    return dp[i][j] = ans;
}

void solve(){
cin>>n>>m;
mat.assign(n,vector<int>(m));
dp.assign(n,vector<int>(m,-1));

for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
        cin>>mat[i][j];
    }
}

cout<<rec(n-1,m-1)<<endl;

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