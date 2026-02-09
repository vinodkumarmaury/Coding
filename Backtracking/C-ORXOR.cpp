#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'


int n;

void helper(int level,int &xrr,int orr,vector<int> &ans,int arr[]){
  if(level==n){
    ans.push_back(orr);
    int temp = ans[0];
    int sz = ans.size();
    for(int i = 1;i<sz;i++){
      temp^=ans[i];
    }
    xrr = min(xrr,temp);
    return;
  }
  helper(level+1,xrr,orr|arr[level],ans,arr);
  ans.push_back(orr);
  helper(level+1,xrr,arr[level],ans,arr);
  ans.pop_back();
}

void solve(){
cin>>n;
int arr[n];
for(int i = 0;i<n;i++){
    cin>>arr[i];
}

int xrr = INT_MAX,orr = 0;
vector<int> ans;
helper(1,xrr,arr[0],ans,arr);
cout<<xrr<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}