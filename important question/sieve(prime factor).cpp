#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e5;

vector<ll> sieve(){
    vector<ll> ans;
    vector<ll> prime(N+1,0);
    for(ll i = 2;i*i<N;i++){
        if(prime[i])continue;
        for(ll j = i*i;j<N;j+=i){
            prime[j] = 1;
        }
    }
    for(int i = 2;i<N;i++){
        if(!prime[i])ans.push_back(i);
    }
    return ans;
}

void solve(){
vector<ll> ans = sieve();

for(auto &x:ans){
    cout<<x<<" ";
}

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}