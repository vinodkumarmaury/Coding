#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'


void solve(){
int n,k;
cin>>n>>k;
int arr[n];
for(int i = 0;i<n;i++){
    cin>>arr[i];
}

unordered_map<int,int> mp; // it will store value with index
int pref = 0;
mp[0] = -1; 
int maxlen = 0;
for(int i = 0;i<n;i++){
    pref^=arr[i];
    int want = pref^k;
    if(mp.count(want)){
    maxlen = max(maxlen,i-mp[want]);
    }
    if(!mp.count(pref)){
        mp[arr[i]] = i;
    }
}
cout<<maxlen<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}