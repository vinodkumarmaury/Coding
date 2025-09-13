#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n;
vector<int> arr;
vector<vector<int>> dp;

int rec(int level,int phase){
    // base case
   // cache check
    if(dp[level][phase]!=-1){
        return dp[level][phase];
    }
    // compute
    int ans = 1;
    for(int i = 0;i<level;i++){
        if(phase==0){
            if(arr[i]>=arr[level])continue;
            ans = max(ans,1+rec(i,0));
        }
        else{
            if(arr[i]<=arr[level])continue;
            ans = max(ans,1+max(rec(i,0),rec(i,1)));
        }
    }
    return dp[level][phase] = ans;
}

void solve(){
cin>>n;
arr.assign(n+1,0);
dp.assign(n+1,vector<int>(2,-1));
for(int i = 0;i<n;i++){
    cin>>arr[i];
}

int ans = 0;

for(int i = 0;i<n;i++){
    for(int p = 0;p<2;p++){
    ans = max(ans,rec(i,p));
    }
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