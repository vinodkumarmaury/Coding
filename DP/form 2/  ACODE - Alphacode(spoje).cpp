#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

ll rec(int level,int n,vector<ll>&dp,const string &s){
    // pruning
    if(level>n) return 0;
    // base case
    if(level==n) return 1;
    if(s[level]-'0'==0) return 0;

    // cache check
    if(dp[level]!=-1) return dp[level];

    ll ans = rec(level+1,n,dp,s);

    if(level+1<n){
        int num1 = s[level]-'0';
        int num2 = s[level+1]-'0';
        int x = num1*10+num2;
        if(x<=26 && x>=10){
            ans += rec(level+2,n,dp,s);
        }
    }
    
    return dp[level] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while(cin >> s){
        if(s=="0") break;
        int n = s.length();
        vector<ll> dp(n+1,-1);
        cout << rec(0,n,dp,s) << endl;
    }
    return 0;
}
