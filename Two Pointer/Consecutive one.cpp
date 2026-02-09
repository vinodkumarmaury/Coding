// You are given a binary array of length **N** and an integer **K**. The **score** of the array is defined as the length of the **longest continuous subsegment** consisting entirely of **1’s**. Your task is to determine the **maximum possible score** after performing **at most K flips**, where each flip allows you to change a **0** into a **1**.

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
void solve(){
int n,k;
cin>>n>>k;
int arr[n];
for(int i = 0;i<n;i++){
    cin>>arr[i];
}
int zero = 0;
int tail = 0,head = -1;
int ans = 0;
while(tail<n){
    while(head+1<n&&((arr[head+1]==0&&zero<k)||(arr[head+1]==1&&zero<=k))){
        head++;
        if(arr[head]==0)zero++;
    }
    ans = max(ans,head-tail+1);
    if(tail>head){
        tail++;
        head = tail-1;
    }
    else{
        if(arr[tail]==0)zero--;
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