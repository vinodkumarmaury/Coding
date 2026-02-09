#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n,k;

bool check(int mid,int arr[]){
if(mid==0)return false;
int count = 0;
for(int i = 1;i<n;i++){
    int d = arr[i]-arr[i-1];
    count+=(d+mid-1)/mid-1;
}
return count<=k;
}

void solve(){
cin>>n>>k;
int arr[n];
for(int i = 0;i<n;i++){
    cin>>arr[i];
}
sort(arr,arr+n);
int low = 0;
int high = 0,ans = 0;
for(int i = 1;i<n;i++){
        high = max(high,arr[i]-arr[i-1]);
}
while(low<=high){
    int mid = low+(high-low)/2;
    if(check(mid,arr)){
        high = mid-1;
        ans = mid;
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