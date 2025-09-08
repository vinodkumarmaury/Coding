#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
void solve(){
string s;
cin>>s;
int n = s.length();
int dp[n+1];
int last[26];
memset(last,-1,sizeof(last));
int prefix[n+1];
dp[0] = 1;
prefix[0] = 1;
for(int i = 1;i<=n;i++){
dp[i] = prefix[i-1];
if(last[s[i-1]-'a']!=-1){
int idx = last[s[i-1]-'a'];
dp[i]-=prefix[idx];
}
last[s[i-1]-'a'] = i-1;
prefix[i] = prefix[i-1]+dp[i];
}
cout<<prefix[n]-1<<endl;
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