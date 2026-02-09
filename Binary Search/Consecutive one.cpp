// You are given a binary array of length **N** and an integer **K**. The **score** of the array is defined as the length of the **longest continuous subsegment** consisting entirely of **1’s**. Your task is to determine the **maximum possible score** after performing **at most K flips**, where each flip allows you to change a **0** into a **1**.


#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

ll n,k;

bool check(ll mid,ll prefix[]){
    for(ll i = 0;i<n-mid+1;i++){
        if(i==0){
            if(mid-prefix[i+mid-1]<=k){
                return true;
            }
        }
        else if(mid-(prefix[i+mid-1]-prefix[i-1])<=k){
            return true;
        }
    }
    return false;
}

void solve(){
cin>>n>>k;
ll arr[n];
ll prefix[n];
for(ll i = 0;i<n;i++){
    cin>>arr[i];
    prefix[i] = arr[i];
    if(i)prefix[i]+=prefix[i-1];
}

ll ans = 0;
ll low = 0,high = n;

while(low<=high){
    ll mid = low+(high-low)/2;
    if(check(mid,prefix)){
        ans = mid;
        low = mid+1;
    }
    else{
        high = mid-1;
    }
}
cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}