#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n;
vector<int> dp;
vector<int> arr;

int rec(int level){
    // pruning
    if(level<0)return 0;
    // base case

    // cache check
    if(dp[level]!=-1)return dp[level];
    // computation
    int best = 0;
    for(int prev_taken = 0;prev_taken<level;prev_taken++){
        if(arr[prev_taken]<arr[level]){
            best = max(best,1+rec(prev_taken));
        }
    }
    // save and return
    return dp[level] = best;
}

void solve(){
cin>>n;
arr.assign(n+1,0);
dp.assign(n+1,-1);
for(int i = 0;i<n;i++){
    cin>>arr[i];
}
int ans = 0;
for(int i = 0;i<n;i++){
    ans = max(ans,rec(i));
}
cout<<ans<<endl;
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