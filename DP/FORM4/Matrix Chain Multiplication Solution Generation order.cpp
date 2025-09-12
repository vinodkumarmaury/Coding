#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n;
vector<int> x,y;
vector<vector<int>> dp;
vector<vector<int>> back;
vector<int> opb,clb;

int rec(int l,int r){
  // prunig
  if(l>r)return 0;
  // base case
  if(l==r)return 0;
  // cache check
  if(dp[l][r]!=-1){
    return dp[l][r];
  }
  // compute
  int ans = 1e9;
  for(int mid = l;mid<r;mid++){
   if(ans>rec(l,mid)+rec(mid+1,r)+x[l]*y[mid]*y[r]){
      ans = rec(l,mid)+rec(mid+1,r)+x[l]*y[mid]*y[r];
      back[l][r] = mid;
    }
  }
  // save and return
  return dp[l][r] = ans;
}

vector<int> ans;

void generate(int l,int r){
  if(l>r)return;
  if(l==r)return;
  opb[l]++;
  clb[r]++;
  int mid = back[l][r];
  generate(l,mid);
  generate(mid+1,r);
}

void solve(){
  cin>>n;
x.assign(n+1,0);
y.assign(n+1,0);
dp.assign(n+1,vector<int>(n+1,-1));
back.assign(n+1,vector<int>(n+1,0));
opb.assign(n+1,0);
clb.assign(n+1,0);
for(int i = 0;i<n;i++){
  cin>>x[i]>>y[i];
}
rec(0,n-1);
generate(0,n-1);
for(int i = 0;i<n;i++){
  for(int j = 0;j<opb[i];j++){
    cout<<"(";
  }
  cout<<i;
  for(int j = 0;j<clb[i];j++){
    cout<<")";
  }
}
cout<<endl;
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