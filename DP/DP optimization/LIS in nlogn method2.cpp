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
vector<int> lis;
for(int i = 0;i<n;i++){
     auto it = lower_bound(lis.begin(),lis.end(),arr[i]);
     int pos = it-lis.begin();
     if(it==lis.end())lis.push_back(arr[i]);
     else *it = arr[i];
}
for(auto &x:lis){
     cout<<x<<" ";
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