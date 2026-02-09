#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

const int inf = 1e9;

void solve(){
int n,k;
cin>>n>>k;
int arr[n];
for(int i = 0;i<n;i++){
    cin>>arr[i];
}
vector<int> dp(n+1,inf);
dp[0] = 0;
for(int i = 1;i<n;i++){
    for(int j = max(0,i-k);j<i;j++){
        dp[i] = min(dp[i],dp[j]+abs(arr[i]-arr[j]));
    }
}
cout<<dp[n-1]<<endl;
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