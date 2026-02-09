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

long double low = 0,high = n;
long double ans = 0; // as per question we will decide low,high and answer

long double eps =  1e-9;

while(abs(low-high)>=eps){
long double mid = low+(high-low)/2;
if(check()){  // as per question we will write check function to make monotocity
    high = mid;
}
else{
    low = mid;
}
ans = mid;
}
cout<<ans<<endl;

// M-2
low = 0,high = n;
ans = 0;
for(int i = 0;i<40;i++){
    long double mid = low+(high-low)/2;
    if(check()){
        high = mid;
    }
    else {
        low = mid;
    }
    ans = mid;
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