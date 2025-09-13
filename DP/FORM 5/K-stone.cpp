#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n,k;
int arr[101];
int dp[100001];

int rec(int kLeft){
    if(kLeft==0){
        return 0;
    }
    if(dp[kLeft]!=-1){
        return dp[kLeft];
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        if(kLeft>=arr[i]){
        if(rec(kLeft-arr[i])==0){
            ans = 1;
            break;
        }
        }
    }
    return dp[kLeft] = ans;
}

void solve(){
cin>>n>>k;
memset(dp,-1,sizeof(dp));
for(int i = 0;i<n;i++){
    cin>>arr[i];
}
if(rec(k)==0){
    cout<<"Second"<<endl;
}
else{
    cout<<"First"<<endl;
}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}