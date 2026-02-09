#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n;
vector<vector<int>> dp;
string s = "0100";

int mathmatically() {
    long long ans = 0;
    for(int k = 0; k <= 3; k++) {
        long long term = 1;
        for(int i = 0; i < k; i++)
            term = term * (n - i) / (i + 1);
        ans += term;
    }
    return ans;
}

int rec(int level,int match){
     if(match==4)return 0;
     if(level==n)return 1;
     if(dp[level][match]!=-1)return dp[level][match];
     int ans = rec(level+1,match+1)+rec(level+1,match);
     return dp[level][match] = ans;
}

void solve(){
cin>>n;
dp.assign(n+1,vector<int>(5,-1));
cout<<rec(0,0)<<endl;
cout<<mathmatically()<<endl;
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