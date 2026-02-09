#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
void solve(){
int n,k;
cin>>n>>k;
string s;
cin>>s;
int arr[26] = {0};
for(int i = 0;i<k;i++){
    char c;
    cin>>c;
    arr[c-'a']++;
}
int head = -1,tail = 0;
ll ans = 0;
while(tail<n){
    while(head+1<n&&arr[s[head+1]-'a']>0){
        head++;
    }
    int len = head-tail+1;
    ans+=len;
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
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}