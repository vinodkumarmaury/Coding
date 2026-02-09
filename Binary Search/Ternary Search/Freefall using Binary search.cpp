#include<bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
#define endl '\n'

ld a,b;

ld func(ll mid){
    return (ld)b*mid+(ld)a/sqrt(mid+1);
}

void solve(){
cin>>a>>b;
ll low = 0;
ll high = (a+b-1)/b;
ll ans = -1;
while(low<=high){
ll mid = low+(high-low)/2;
if(func(mid)<=func(mid+1)){
    ans = mid;
    high = mid-1;
}
else{
    low = mid+1;
}
}
assert(ans!=-1);
cout<<fixed<<setprecision(15)<<func(ans)<<endl;
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