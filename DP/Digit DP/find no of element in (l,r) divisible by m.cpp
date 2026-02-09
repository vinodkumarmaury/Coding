#include<bits/stdc++.h>
using namespace std;
// using ll = long long;
#define int long long
#define endl '\n'


string L,R;

int n;
int l,r,m;
int dp[20][2][2][3001];

void build_string(int l,int r){
L = to_string(l);
R = to_string(r);
// cout<<L<<" "<<R<<endl;
reverse(L.begin(),L.end());

while(L.size()!=R.size()){
    L+='0';
}

reverse(L.begin(),L.end());
// cout<<L<<" "<<R;
}

int rec(int level,int tlo,int thi,int rem){
    if(level==n){
        return rem==0;
    }
    if(dp[level][tlo][thi][rem]!=-1)return dp[level][tlo][thi][rem];

    int ans = 0;
    int lo = 0,high = 9;
    if(tlo)lo = L[level]-'0';
    if(thi)high = R[level]-'0';

   for(int digit = lo;digit<=high;digit++){
    int ntlo = tlo, nthi = thi;
    if(digit!=L[level]-'0')ntlo = 0;
    if(digit!=R[level]-'0')nthi = 0;
    ans+=rec(level+1,ntlo,nthi,(rem+digit)%m);
   }
   
   return dp[level][tlo][thi][rem] = ans;
}

void solve(){

cin>>l>>r>>m; // L,R upto 1e18, 1<=m<=3000

build_string(l,r);
n = L.size();
memset(dp,-1,sizeof(dp));
cout<<rec(0,1,1,0)<<endl;

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