#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int mod = 1e9+7;
int n;
string s;

int rec(int level,int currentSum,int totalSum){
    if(level==n)return (totalSum+currentSum)%mod;
    int digit = s[level]-'0';
    int ans = rec(level+1,(currentSum*10+digit)%mod,totalSum);
    ans = (ans+rec(level+1,digit,(currentSum+totalSum)%mod))%mod;
    return ans;
}

void solve(){
cin>>s;
n = s.length();
cout<<rec(1,s[0]-'0',0)<<endl;
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