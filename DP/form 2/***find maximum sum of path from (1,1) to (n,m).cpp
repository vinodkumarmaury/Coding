#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n,m;
vector<vector<int>> mat;
vector<vector<int>> dp,done;

int rec(int r,int c){
    // pruning
    if(r<0||c<0){
        return -1e9;
    }
    // base case
    if(r==0&&c==0){
        return mat[r][c];
    }

    // cache check
    if(done[r][c]){  
        return dp[r][c];
    }
    // compute
    int ans = -1e9;
    if(r!=0){
        ans = max(ans,rec(r-1,c)+mat[r][c]);  // it may return -1 but actual value is not -1 so to avoid it we are using done to track 
    }
    if(c!=0){
        ans = max(ans,rec(r,c-1)+mat[r][c]);
    }
    done[r][c] = 1;
    return dp[r][c] = ans;
}

void solve(){
cin>>n>>m;
mat.assign(n+1,vector<int>(m+1,0));
dp.assign(n+1,vector<int>(m+1,-1));
done.assign(n+1,vector<int>(m+1,0));
for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
        cin>>mat[i][j]; 
    }
}

cout<<rec(n-1,m-1)<<endl;

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