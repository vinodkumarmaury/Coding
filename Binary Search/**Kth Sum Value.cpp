// You are given two arrays — **A** of size **N** and **B** of size **M**, along with an integer **K**. From these, you need to construct a new array **C** of size **N × M**, where each element of **C** is formed by adding every element of **A** with every element of **B**, i.e., **C = {A[i] + B[j] | 1 ≤ i ≤ N, 1 ≤ j ≤ M}**. The task is to determine the **Kth smallest element** in this newly formed array **C**.
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
void solve(){
ll n,m,k;
cin>>n>>m>>k;
vector<ll> arr(n);
for(ll i = 0;i<n;i++){
    cin>>arr[i];
}
vector<ll> brr(m);
for(ll i = 0;i<m;i++){
    cin>>brr[i];
}
sort(arr.begin(),arr.end());
sort(brr.begin(),brr.end());
if(n<m){
    ll low = arr[0]+brr[0];
    ll high = arr[n-1]+brr[m-1];
    ll ans = high;
    while(low<=high){
        ll mid = low+(high-low)/2;
        ll cnt = 0;
        for(ll i = 0;i<n;i++){
            cnt+=upper_bound(brr.begin(),brr.end(),mid-arr[i])-brr.begin();
        }
        if(cnt>=k){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout<<ans<<endl;
}
else{
    ll low = arr[0]+brr[0];
    ll high = arr[n-1]+brr[m-1];
    ll ans = high;
    while(low<=high){
        ll mid = low+(high-low)/2;
        ll cnt = 0;
        for(ll i = 0;i<m;i++){
            cnt+=upper_bound(arr.begin(),arr.end(),mid-brr[i])-arr.begin();
        }
        if(cnt>=k){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout<<ans<<endl;
}

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