#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
const int inf = 1e9;

int n,k;
vector<int> dp;
int rec(int level,int arr[]){
    if(level==n-1){
    return 0;
    }
  
  if(dp[level]!=-1){
    return dp[level];
  }

int ans = INT_MAX;

for (int i = 1; i <= k && level + i < n; i++){
    ans = min(ans,abs(arr[level+i]-arr[level])+rec(level+i,arr));
}

return dp[level] = ans;

}

void solve(){
cin>>n>>k;
dp.resize(n+1,-1);
int arr[n];
for(int i = 0;i<n;i++){
    cin>>arr[i];
}
cout<<rec(0,arr)<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}