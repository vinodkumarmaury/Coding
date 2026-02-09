#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
void solve(){
int n,q;
cin>>n>>q;
int arr[n];
for(int i = 0;i<n;i++){
    cin>>arr[i];
}
int prefix[n+1];
prefix[0] = 0;
for(int i = 0;i<n;i++){
    prefix[i+1] = prefix[i]^arr[i];
}
while(q--){
    int a,b;
    cin>>a>>b;
    int num = prefix[b]^prefix[a-1];
    cout<<num<<endl;
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