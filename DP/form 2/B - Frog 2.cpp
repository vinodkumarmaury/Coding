#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n,k;
vector<int> arr,dp;

int rec(int level){
    // base case
    if(level==0) return dp[0] = 0;

    // cache check
    if(dp[level]!=-1) return dp[level];

    int best = 1e9;
    for(int j=1;j<=k;j++){
        if(level-j>=0){
            best = min(best, rec(level-j) + abs(arr[level]-arr[level-j]));
        }
    }

    return dp[level] = best;
}

void solve(){
    cin>>n>>k;
    arr.resize(n);
    dp.assign(n,-1);
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<rec(n-1)<<endl;
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
