// from array we can take value 0 to arr[i];

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n,s;
vector<vector<int>> dp1,dp2;
vector<int> arr;

int rec(int level,int sum_left){
    if(sum_left<0)return 0;
    if(level==n){
        return sum_left==0;
    }
    if(dp1[level][sum_left]!=-1)return dp1[level][sum_left];
    // skip
    int ans = rec(level+1,sum_left);
    for(int i = 1;i<=arr[level];i++){
        ans+=rec(level+1,sum_left-i);
    }
    return dp1[level][sum_left] = ans;
}

void solve(){
cin>>n>>s;
arr.assign(n,0);
dp1.assign(n+1,vector<int>(s+1,-1));
dp2.assign(2,vector<int>(s+1,-1));
for(int i = 0;i<n;i++){
    cin>>arr[i];
}
cout<<rec(0,s)<<endl;

cout<<"iterative solution"<<endl;

for(int i = n;i>=0;i--){
    for(int j = 0;j<=s;j++){
        if(i==n){
            if(j==0){
                dp2[i&1][j] = 1;
            }
            else{
                dp2[i&1][j] = 0;
            }
            continue;
        }
        dp2[i&1][j] = dp2[(i+1)&1][j];
        if(j-arr[i]-1>=0){
            dp2[i&1][j]-=dp2[(i+1)&1][j-arr[i]-1];
        }
    }
    for(int j = 1;j<=s;j++){
        dp2[i&1][j]+=dp2[i&1][j-1];
    }
}
cout<<dp2[0][s]-dp2[0][s-1]<<endl;
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