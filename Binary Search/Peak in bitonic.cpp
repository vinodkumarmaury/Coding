#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
int n;

bool check(int mid,int arr[]){
if(mid==n-1)return true;
if(arr[mid]>arr[mid+1])return true;
    return false;
}

void solve(){
cin>>n;
int arr[n];
for(int i = 0;i<n;i++){
    cin>>arr[i];
}
int ans = n,low = 0,high = n-1;
while(low<=high){
    int mid = low+(high-low)/2;
    if(check(mid,arr)){
        ans = mid;
        high = mid-1;
    }
    else{
        low = mid+1;
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