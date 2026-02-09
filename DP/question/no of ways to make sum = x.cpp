#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n,x;
vector<int> arr;
vector<vector<int>> dp;
int rec(int level, int sumLeft){
    // prune
     if(sumLeft<0)return 0;
    // base case
     if(level==n){
        if(sumLeft==0)return 1;
        return 0;
     }
    // cache check
    if(dp[level][sumLeft]!=-1){
        return dp[level][sumLeft];
    }
    // transition
    int ans= rec(level+1,sumLeft)+rec(level+1,sumLeft-arr[level]);
    // save and return;
    return dp[level][sumLeft] = ans;
}

void solve(){
cin>>n>>x;
arr.resize(n);
dp.resize(n+1,vector<int>(x+1,-1));
for(int i = 0;i<n;i++){
    cin>>arr[i];
}
cout<<rec(0,x)<<endl;
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