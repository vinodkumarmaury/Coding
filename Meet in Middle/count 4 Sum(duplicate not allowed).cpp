#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
void solve(){
int n,x;
cin>>n>>x;
int arr[n];
for(int i = 0;i<n;i++){
    cin>>arr[i];
}

map<int,int> mp;
int count  = 0;

for(int b = n-2;b>=1;b--){
    for(int a = 0;a<b;a++){
        int num = x-(arr[a]+arr[b]);
        if(mp.find(num)!=mp.end()){
            count+=mp[num];
        }
    }
    int c = b;
    for(int i = c+1;i<n;i++){
        mp[arr[i]+arr[c]]++;
    }
}

cout<<count<<endl;

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