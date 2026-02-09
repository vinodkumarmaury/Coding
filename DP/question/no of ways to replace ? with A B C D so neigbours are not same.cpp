#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n;
string s;
vector<vector<int>> dp;

int rec(int level, int last){
    // prune

    // base case
     if(level==n){
        return 1;
     }
    // cache check
    if(last!=-1&&dp[level][last]!=-1){
        return dp[level][last];
    }
    // transaction
    
    int ans = 0;

    if(s[level]=='?'){
         for(int ch = 0;ch<4;ch++){
            if(ch==last)continue;
            ans+=rec(level+1,ch);
         }
    }
    else {
        if(s[level]-'A'==last){

        }
        else{
            ans+=rec(level+1,s[level]-'A');
        }
    }
    // save and return
    if(last !=-1){
        return dp[level][last] = ans;
    }
    else{
        return ans;
    }
}

void solve(){
cin>>n;
cin>>s;
dp.resize(n+1,vector<int>(4,-1));
cout<<rec(0,-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}