// we can merge only neigbour element only and then new element will be arr[i]+arr[j], j = i+/-1, benefit = arr[i]*arr[j]

#include<bits/stdc++.h>
using namespace std;
const int mod = 100;
using ll = long long;
#define endl '\n'

int n;
vector<int> arr;
vector<vector<int>> dp;

int rec(int l,int r){
  // pruning
  // base case
  if(l==r)return 0;
  // cache check
  if(dp[l][r]!=-1)return dp[l][r];
  // compute
  int ans = 0;
  int sum = 0;
  int total = 0;
  for(int i = l;i<=r;i++){
    total+=arr[i];
  }

  for(int mid = l;mid<r;mid++){
    sum+=arr[mid];
    ans = max(ans,rec(l,mid)+rec(mid+1,r)+sum*(total-sum));
  }
  // save and return
  return dp[l][r] = ans;
}

void solve(){
cin>>n;
arr.assign(n,0);
dp.assign(n+1,vector<int>(n+1,-1));
for(int i = 0;i<n;i++){
    cin>>arr[i];
}
cout<<rec(0,n-1)<<endl;
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