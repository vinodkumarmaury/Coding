#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
void solve(){
int n,k,q;
cin>>n>>k>>q;
int arr[n];
for(int i = 0;i<n;i++){
    cin>>arr[i];
}
int head = -1,tail = 0;
ll ans = 0;
while(tail<n){
    while(head+1<n&&arr[head+1]<=q){
       head++;
    }
    int len = head-tail+1;
    if(len>=k){
    ans+=len-k+1;
    }
    if(tail>head){
        tail++;
        head = tail-1;
    }
    else{
    tail++;
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