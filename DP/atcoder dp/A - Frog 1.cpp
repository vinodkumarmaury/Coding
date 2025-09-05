#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
const int inf = 1e9;

int n;
vector<int> dp;
int rec(int level,int arr[]){
    if(level==n-1){
    return 0;
    }
  
  if(dp[level]!=-1){
    return dp[level];
  }

int ans = INT_MAX;

if(level+1<n){
ans = min(ans,rec(level+1,arr)+abs(arr[level+1]-arr[level]));
}

if(level+2<n){
    ans = min(ans,rec(level+2,arr)+abs(arr[level+2]-arr[level]));
}

return dp[level] = ans;

}

void solve(){
cin>>n;
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