#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n;
string s;
vector<vector<int>> dp1;
vector<int> dp2;

int rec1(int l,int r){
  if(l>=r)return 1;
  if(dp1[l][r]!=-1)return dp1[l][r];
  int ans = 0;
  ans = (s[l]==s[r])&&rec1(l+1,r-1);
  return dp1[l][r] = ans;
}

int rec2(int level){
  // base case
  if(level==0){
   return -1;
  }
  if(dp2[level]!=-1){
    return dp2[level];
  }
  int ans = 1e9;
  for(int i = 0;i<level;i++){
    if(rec1(i,level-1)){ // to make 0 based indexing
      ans = min(ans,1+rec2(i));
    }
  }
  return dp2[level] = ans;
}

void solve(){
cin>>n;
cin>>s;
dp1.assign(n+1,vector<int>(n+1,-1));
dp2.assign(n+1,-1);
cout<<rec2(n)<<endl;
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