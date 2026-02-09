#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

string L,R;
int n;
int dp[20][2][2][2][10]; // level,tlow,thigh,zeroCheck,lastDigit

int rec(int level,int tl,int thi,int zero,int last){
    if(level==n){
        return 1;
    }
    if(dp[level][tl][thi][zero][last]!=-1)return dp[level][tl][thi][zero][last];

    int low = 0,high = 9;
    if(tl)low = L[level]-'0';
    if(thi)high = R[level]-'0';
    int ans = 0;
    for(int digit = low;digit<=high;digit++){
        if(!zero&&digit==last)continue;
        int ntl = tl,nth = thi;
        if(digit!=L[level]-'0')ntl = 0;
        if(digit!=R[level]-'0')nth = 0;
        int nzero = zero;
        if(digit!=0){
         nzero = 0;
        }
        ans+=rec(level+1,ntl,nth,nzero,digit);
    }

    return dp[level][tl][thi][zero][last] = ans;
}

void build_string(int l,int r){
    L = to_string(l);
    R = to_string(r);

    reverse(L.begin(),L.end());

    while(L.size()!=R.size()){
        L+='0';
    }
    reverse(L.begin(),L.end());
}

void solve(){
int l,r;
cin>>l>>r;
build_string(l,r);
n = R.size();
memset(dp,-1,sizeof(dp));
cout<<rec(0,1,1,1,0)<<endl;
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