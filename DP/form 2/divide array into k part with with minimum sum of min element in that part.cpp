#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

vector<int> arr;
int n,k;
vector<vector<int>> dp;

int rec(int level,int Kleft){
// pruning
if(Kleft<0)return 1e9;
// base case
if(level==-1){
    if(Kleft==0){
        return 0;
    }
    else{
        return 1e9;
    }
}
// cache check
if(dp[level][Kleft]!=-1){
    return dp[level][Kleft];
}
// compute
int ans = 1e9;
int minSeen = arr[level];
for(int i = level-1;i>=-1;i--){
    ans = min(ans,rec(i,Kleft-1)+minSeen);
    minSeen = min(minSeen,arr[i]);
}
// save and return
return dp[level][Kleft] = ans;
}

void solve(){
cin>>n>>k;
arr.assign(n+1,0);
dp.assign(n+1,vector<int>(k+1,-1));
for(int i = 0;i<n;i++){
    cin>>arr[i];
}
cout<<rec(n-1,k)<<endl;
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