// "Find the number of subarrays that you can make all ones by less than 'k' flips
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;

bool check(int mid,int prefix[],int k,int st){
    int numOfZero = (mid-st+1-(prefix[mid]-(st>0?prefix[st-1]:0)));
    if(numOfZero<=k)return true;
    return false;
}

#define endl '\n'
void solve(){
int n,k;
cin>>n>>k;
int arr[n];
int prefix[n];
for(int i = 0;i<n;i++){
    cin>>arr[i];
    prefix[i] = arr[i];
    if(i){
        prefix[i]+=prefix[i-1];
    }
}
int count = 0;
for(int st = 0;st<n;st++){
    int ans = st-1;
    int low = st;
    int high = n-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(check(mid,prefix,k,st)){
            low = mid+1;
            ans = mid;
        }
        else{
            high = mid-1;
        }
    }
    count+=(ans-(st-1));
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