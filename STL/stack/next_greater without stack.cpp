#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
void solve(){
int n;
cin>>n;
int arr[n];
for(int i = 0;i<n;i++){
    cin>>arr[i];
}
int nge[n];
for(int i = n-1;i>=0;i--){
    int next_index = i+1;
    while(next_index<n&&arr[next_index]<=arr[i]){
        next_index = nge[next_index];
    }
    nge[i] = next_index;
}
for(int i = 0;i<n;i++){
    cout<<nge[i]<<" ";
}
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