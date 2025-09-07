#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n;
vector<int> weight,value;
vector<vector<int>> dp;
int rec(int level,int W_left){
   
   // pruning
    // if(W_left<0)return -1e9;
    // base case;
    if(level==n){
        return 0;
    }

    // cache check;
    if(dp[level][W_left]!=-1){
        return dp[level][W_left];
    }

    // transition phase
    int ans = rec(level+1,W_left);
    if(W_left>=weight[level]){
        ans = max(ans,rec(level,W_left-weight[level])+value[level]);
    }
   return dp[level][W_left] =  ans;
}

vector<int> ans;

void generate(int level,int W_left){
if(level==n){
    return;
}

// Don't take;
int dont_take = rec(level+1,W_left);
if(W_left>=weight[level]){
    int take = rec(level,W_left-weight[level])+value[level];
    if(take>dont_take){
        ans.push_back(level);
        generate(level,W_left-weight[level]);
    }
    else{
        generate(level+1,W_left);
    }
}
else{
    generate(level+1,W_left);
}

}

void solve(){
cin>>n;
weight.assign(n+1,0);
value.assign(n+1,0);
for(int i = 0;i<n;i++){
    cin>>weight[i];
}
for(int i = 0;i<n;i++){
    cin>>value[i];
}
int w;
cin>>w;
dp.assign(n+1, vector<int>(w+1, -1));
cout<<rec(0,w)<<endl;
generate(0,w);
cout<<ans.size()<<endl;
for(auto &x:ans){
    cout<<x<<" ";
}
cout<<endl;
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
