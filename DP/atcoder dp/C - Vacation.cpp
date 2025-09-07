#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
const int inf = 1e9;

int n;
vector<vector<int>> mat;
vector<vector<int>> dp;

int rec(int level,int last){
    if(level==n){
        return 0;
    }

   if(last!=-1&&dp[level][last]!=-1){
    return dp[level][last];
   }

int ans = -inf;
for(int i = 0;i<=2;i++){
    if(last!=i){
        ans = max(ans,rec(level+1,i)+mat[level][i]);
    }
}
if(last!=-1){
dp[level][last] = ans;
}
return ans;
}

void solve(){
cin>>n;
dp.assign(n+1,vector<int>(3,-1));
mat.assign(n+1,vector<int>(3));
for(int i = 0;i<n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    mat[i][0] = a;
    mat[i][1] = b;
    mat[i][2] = c;
}

cout<<rec(0,-1)<<endl;
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