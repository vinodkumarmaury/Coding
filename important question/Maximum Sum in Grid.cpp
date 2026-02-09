// Given a grid of size n×m with integers, you need to find the maximum sum subgrid (contiguous rectangular submatrix) present in the grid. A subgrid is defined by choosing a contiguous range of rows and a contiguous range of columns; the sum is the total of all elements inside that rectangle.
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

ll kadan(vector<ll>prefix){
    ll res = prefix[0];
    int n = prefix.size();
    ll maxi = prefix[0];
    for(int i = 1;i<n;i++){
        maxi = max(prefix[i],maxi+prefix[i]);
        res = max(res,maxi);
    }
    return res;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    ll arr[n][m];
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    ll sum = INT_MIN;
    if(m<n){
        for(ll c1 = 0;c1<m;c1++){
            vector<ll> prefix(n,0);
            for(ll c2 = c1;c2<m;c2++){
                for(ll r = 0;r<n;r++){
                    prefix[r]+=arr[r][c2];
                }
            sum = max(sum,kadan(prefix));
            }
        }
    }
    else{
        for(ll r1 = 0;r1<n;r1++){
            vector<ll> prefix(m,0);
            for(ll r2 = r1;r2<n;r2++){
                for(ll c = 0;c<m;c++){
                    prefix[c]+=arr[r2][c];
                }
            sum = max(sum,kadan(prefix));
            }
        }
    }
    cout<<sum<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}