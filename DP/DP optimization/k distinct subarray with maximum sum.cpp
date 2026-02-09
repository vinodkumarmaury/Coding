#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

vector<int> prefix;
vector<vector<int>> dp;
vector<vector<int>> done;
const int inf = 1e9;

int rec(int level,int Kleft){
    if(level<0){
        if(Kleft==0)return 0;
        else return -inf;
    }
    if(Kleft <= 0){
        if(Kleft==0)return 0;
        else return -inf;
    }
    if(done[level][Kleft]){
        return dp[level][Kleft];
    }
    int ans = rec(level-1,Kleft);
    for(int j = 1;j<=level+1;j++){
        ans = max(ans,rec(level-j,Kleft-1)+prefix[level+1]-prefix[level+1-j]);
    }
    done[level][Kleft] = 1;
    return dp[level][Kleft] = ans;
}

void solve(){
int n,k;
cin>>n>>k;
prefix.assign(n+1,0);
int arr[n];
dp.assign(n+1,vector<int>(k+1,-1));
done.assign(n+1,vector<int>(k+1,0));
for(int i = 0;i<n;i++){
    cin>>arr[i];
    prefix[i+1]+=prefix[i]+arr[i];
}
cout<<rec(n-1,k)<<endl;
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