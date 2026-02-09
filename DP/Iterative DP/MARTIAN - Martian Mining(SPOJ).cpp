#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int dp[502][502];
int dp2[502][502];
int n,m;

int arr[502][502],brr[502][502];
int prefix_arr[502][502],prefix_brr[502][502];

int rec(int i,int j){
if(i==0||j==0)return 0;
if(dp[i][j]!=-1)return dp[i][j];
int ans = rec(i-1,j)+prefix_arr[i][j];
ans = max(ans,rec(i,j-1)+prefix_brr[i][j]);
return dp[i][j] = ans;
}

void solve(){
memset(dp,-1,sizeof(dp));
memset(dp2,0,sizeof(dp2));
for(int i = 1;i<=n;i++){
    for(int j = 1;j<=m;j++){
        cin>>arr[i][j];
    }
}
for(int i = 1;i<=n;i++){
    for(int j = 1;j<=m;j++){
        cin>>brr[i][j];
    }
}

for(int i = 1;i<=n;i++){
    int s = 0;
    for(int j = 1;j<=m;j++){
    s+=arr[i][j];
    prefix_arr[i][j] = s;
    }
}
for(int j = 1;j<=m;j++){
    int s = 0;
    for(int i = 1;i<=n;i++){
    s+=brr[i][j];
    prefix_brr[i][j] = s;
    }
}

cout<<rec(n,m)<<endl;

for(int i = 1;i<=n;i++){
    for(int j = 1;j<=m;j++){
     dp2[i][j] = max(dp2[i][j],dp2[i-1][j]+prefix_arr[i][j]);
     dp2[i][j] = max(dp2[i][j],dp2[i][j-1]+prefix_brr[i][j]);
    }
}
cout<<dp2[n][m]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(true){
        cin>>n>>m;
       if (n==0&&m==0) break;
        solve();
    }
    return 0;
}