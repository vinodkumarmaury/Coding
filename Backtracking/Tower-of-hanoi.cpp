#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
 
void helper(int n,int from, int to, int support,int ans){
if(n==0){
    return;
}
helper(n-1,from,support,to,ans+1);
cout<<from<<" "<<to<<endl;
helper(n-1,support,to,from,ans+1);
}
 
void solve(){
int n;
cin>>n;
cout<<((1<<n)-1)<<endl;
helper(n,1,3,2,0);
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1	;
    while(t--){
        solve();
    }
    return 0;
}
