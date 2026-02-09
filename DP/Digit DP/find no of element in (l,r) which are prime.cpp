#include<bits/stdc++.h>
using namespace std;
// using ll = long long;
#define int long long
#define endl '\n'


string L,R;

int n;
int l,r;
int dp[20][2][2][16];

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

int rec(int level,int tlo,int thi,int mask){
    if(level==n){
        return mask==15;
    }
    if(dp[level][tlo][thi][mask] !=-1)return dp[level][tlo][thi][mask];

    int ans = 0;
    int lo = 0,high = 9;
    if(tlo)lo = L[level]-'0';
    if(thi)high = R[level]-'0';

   for(int digit = lo;digit<=high;digit++){
    int ntlo = tlo, nthi = thi;
    if(digit!=L[level]-'0')ntlo = 0;
    if(digit!=R[level]-'0')nthi = 0;
     int nmask = mask;
        if (digit == 2) nmask |=(1<<0);
        if (digit == 3) nmask |=(1<<1);
        if (digit == 5) nmask |=(1<<2);
        if (digit == 7) nmask |=(1<<3);
        ans += rec(level+1,ntlo,nthi,nmask);
   }
   
   return dp[level][tlo][thi][mask]  = ans;
}

void solve(){

cin>>l>>r; // L,R upto 1e18, 1<=m<=3000

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