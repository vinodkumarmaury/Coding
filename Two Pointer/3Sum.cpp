#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
void solve(){
    int n;
    ll target;
    cin>>n>>target;
    vector<ll>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());

    ll ans=1e18;
    for(int j=0;j<n;j++){
        int i=0;
        int k=n-1;

        while(i<j && k>j){
            if(arr[i]+arr[j]+arr[k]==target){
                cout<<0<<endl;
                return;
            }
            else if(arr[i]+arr[j]+arr[k]>target){
                ans=min(ans,abs(arr[i]+arr[j]+arr[k]-target));
                k--;
            }
            else{
                 ans=min(ans,abs(arr[i]+arr[j]+arr[k]-target));
                i++;
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}