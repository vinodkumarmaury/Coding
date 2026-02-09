#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

// arr[] 0 0 0 .... 1 1 1
// we have to find where first 1 occurs;

bool check(int mid,int arr[]){
    if(arr[mid]==1)return 1;
    return 0;
}

void solve(){
int n;
cin>>n;
int arr[n];
for(int i = 0;i<n;i++){
    cin>>arr[i];
}
int low = 0,high = n-1,ans = -1;
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