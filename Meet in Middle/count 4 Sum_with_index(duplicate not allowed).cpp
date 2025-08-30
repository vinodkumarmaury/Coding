// Duplicate allowed
// 0<=a,b,c,d<n such that arr[a]+arr[b]+arr[c]+arr[d] = x;

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

map<int,int> sums;

for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
        sums[arr[i]+arr[j]]++;
    }
}

ll count = 0;

for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
        int num = x-arr[i]+arr[j];
        auto it = sums.find(num);
        if(it!=sums.end()){
            cout<<"YES"<<endl;
            return;
        }
    }
}

cout<<"NO"<<endl;

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