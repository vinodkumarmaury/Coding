#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

vector<pair<ll,ll>> helper(vector<ll> arr,vector<ll> brr){
    ll n = arr.size();
    vector<pair<ll,ll>> ans;
    for(ll mask = 0;mask<(1<<n);mask++){
        ll x = 0,y = 0;
     for(ll i = 0;i<n;i++){
        if((mask>>i)&1){
          x+=arr[i];
          y+=brr[i];
        }
     }
     ans.push_back({x,y});
    }
    return ans;
}


void solve(){
ll n,budget;
cin>>n>>budget;
vector<ll> cost(n);
for(ll i = 0;i<n;i++){
    cin>>cost[i];
}
vector<ll> profit(n);
for(ll i = 0;i<n;i++){
    cin>>profit[i];
}
ll mid = n/2;
vector<ll> x(cost.begin(),cost.begin()+mid);
vector<ll> y(profit.begin(),profit.begin()+mid);
vector<pair<ll,ll>> left = helper(x,y);
vector<ll> xx(cost.begin()+mid,cost.end());
vector<ll> yy(profit.begin()+mid,profit.end());
vector<pair<ll,ll>> right = helper(xx,yy);

sort(right.begin(),right.end());

ll ans = LLONG_MIN;

for(ll i = 1;i<right.size();i++){
    right[i].second = max(right[i].second,right[i-1].second);
}

for(ll i = 0;i<left.size();i++){
    ll costing = left[i].first;
    ll profiting = left[i].second;
    if(costing>budget)continue;
    pair<ll,ll> p = {budget-costing,LLONG_MAX};
    auto it = upper_bound(right.begin(),right.end(),p);
    if(it!=right.begin()){
        it--;
        pair<ll,ll> temp = *it;
        ans = max(profiting+temp.second,ans);
    }
    else{
      ans = max(ans,profiting);
    }
}
cout<<ans<<endl;
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