#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const int inf = 1e9;

int n,k;
vector<int> arr;
int dp[301][301][301];

int rec(int l,int r,int kleft){
    if(l>r||kleft<=0)return inf;
    if(r-l+1<kleft)return inf;
    if(kleft==1){
        int maxi = 0;
        for(int i = l;i<=r;i++){
            maxi = max(maxi,arr[i]);
        }
        return maxi;
    }
    if(dp[l][r][k]!=-1)return dp[l][r][k];
    int maxi = 0;
    int ans = inf;
    for(int mid = l;mid<r;mid++){
    maxi = max(maxi,arr[mid]);
    ans = min(ans,rec(mid+1,r,kleft-1)+maxi);
    } 
    return dp[l][r][kleft] = ans;
}

void solve(){
cin>>n>>k;
arr.assign(n+1,0);
for(int i = 0;i<n;i++){
    cin>>arr[i];
}

memset(dp,-1,sizeof(dp));

cout<<rec(0,n-1,k);

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