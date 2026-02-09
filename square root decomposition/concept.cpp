
// we first divide question asked in block size with their answer then as per range query we will use it. It may be range is not starting point of block so we will first reach there by linearly then start jumping again at the end we may need linear because end point may not any blocks end point.

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
const int N = 1e5+14, S = 300;
int n,q,arr[N],brr[N];

void solve(){
cin>>n;
for(int i = 0;i<n;i++){
    cin>>arr[i];
}
for(int i = 0;i<n;i+=S){
    brr[i/S] = *min_element(arr+i,arr+min(i+S,n));
}
cin>>q;
while(q--){
    int l,r;
    cin>>l>>r;
    int ans = INT_MAX;
    while(l<=r){
        if(l%S==0&&l+S<r){
         ans = min(ans,brr[l/S]);
         l+=S;
        }
        else{
            ans = min(ans,arr[l++]);
        }
    }
    cout<<ans<<endl;
}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}