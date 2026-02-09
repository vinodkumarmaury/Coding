#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n;
vector<vector<ll>> dp,arr;

ll rec(int i,int j){
    if(i>=n||j>=n)return 0;
    if(i==n&&j==n)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    ll ans = 0;
    for(int x = i+1;x<n;x++){
        ans = (ans+rec(x,j)+arr[x][j])%mod;
    }
    for(int y = j+1;y<n;y++){
        ans = (ans+rec(i,y)+arr[i][y])%mod;
    }
    return dp[i][j] = ans;
}

void solve(){
cin>>n;
dp.assign(n+1,vector<ll>(n+1,-1));
arr.assign(n,vector<ll>(n,0));
for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
        cin>>arr[i][j];
    }
}
ll ans = 0;
// for(int i = 0;i<n;i++){
//     for(int j = 0;j<n;j++){
//         ans = (ans+rec(i,j))%mod;
//     }
// }
cout<<rec(0,0)<<endl;
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