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
while(high-low>=3){
    ll mid1 = (2*low+high)/3;
    ll mid2 = (low+2*high)/3;
    if(func(mid1)<func(mid2)){
        high = mid2;
    }
    else{
        low = mid1;
    }
}

ld ans = a;
for(ll i = low;i<=high;i++){
    ans = min(ans,func(i));
}
cout<<fixed<<setprecision(15)<<ans<<endl;
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