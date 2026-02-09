#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int rec(int a,int p,int k){
  if(a==0&&p<k)return 0;
  return a+(a+p)/k+rec((a+p)/k,(a+p)%k,k);
}

void solve(){
int a = 3,p = 3;
int k = 2;
cout<<rec(a,p,k)<<endl;
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