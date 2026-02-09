#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
#define endl '\n'
void solve(){
int n;
cin>>n;
int arr[n];
priority_queue<int> pq;
for(int i = 0;i<n;i++){
    cin>>arr[i];
    pq.push(-arr[i]);
}
int brr[n];
for(int i = 0;i<n;i++){
    cin>>brr[i];
}



// sort(brr,brr+n);
int i = 0;
while(i<n){
    if(brr[i]!=1){
        i++;
        continue;
    }
    int x = pq.top();
    pq.pop();
    x--;
    pq.push(x);
    i++;
}

int ans = 1;

for(int i = 0;i<n;i++){
    int x = -pq.top();
    pq.pop();
    ans = (ans*x*brr[i])%mod;
}
cout<<ans<<endl;
}

signed main(){
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