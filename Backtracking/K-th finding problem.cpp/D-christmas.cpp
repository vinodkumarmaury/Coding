#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
// using ll = long long;
#define int long long
#define endl '\n'
int bun[51],pat[51];
void preCalc(){
bun[0] = 0;
pat[0] = 1;

for(int i = 1;i<51;i++){
    bun[i] = 2+2*bun[i-1];
    pat[i] = 1+2*pat[i-1];
}
}
int helper(int n,int x){
    if(n==0){
        if(x>=1)return 1;
        return 0;
    }
    int ans = 0;
   if(x>=1){
   x-=1;
   }
   else return ans;
   if(x>=bun[n-1]+pat[n-1]){
    x-=bun[n-1]+pat[n-1];
     ans+=pat[n-1];
   }
   else {
    return ans+helper(n-1,x);
   }
   if(x>=1){
    x-=1;
    ans++;
   }
  if(x>=bun[n-1]+pat[n-1]){
    x-=bun[n-1]+pat[n-1];
    ans+=pat[n-1];
   }
   else {
    return ans+helper(n-1,x);
   }
    if(x>=1){
    x-=1;
   }
   return ans;
}

void solve(){
int n,x;
cin>>n>>x;
cout<<helper(n,x);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    preCalc();
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}