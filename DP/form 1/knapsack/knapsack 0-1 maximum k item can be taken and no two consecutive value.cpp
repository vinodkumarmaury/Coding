#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n,k;
vector<int> weight,value;
vector<vector<vector<vector<int>>>> dp;
int rec(int level,int W_left,int itemLeft,int check){
   
   // pruning
    if(itemLeft<0)return -1e9;
    // base case;
    if(level==n){
        return 0;
    }

    // cache check;
    if(dp[level][W_left][itemLeft][check]!=-1){
        return dp[level][W_left][itemLeft][check];
    }

    // transition phase
    int ans = rec(level+1,W_left,itemLeft,0);
    if(W_left>=weight[level]&&!check){
        ans = max(ans,rec(level+1,W_left-weight[level],itemLeft-1,1)+value[level]);
    }
   return dp[level][W_left][itemLeft][check] =  ans;
}

vector<int> ans;

void generate(int level,int W_left,int itemLeft,int check){
if(itemLeft<0)return;
if(level==n){
    return;
}

// Don't take;
int dont_take = rec(level+1,W_left,itemLeft,0);
if(W_left>=weight[level]&&itemLeft>0&&!check){
    int take = rec(level+1,W_left-weight[level],itemLeft-1,1)+value[level];
    if(take>dont_take){
        ans.push_back(level);
        generate(level+1,W_left-weight[level],itemLeft-1,1);
    }
    else{
        generate(level+1,W_left,itemLeft,0);
    }
}
else{
    generate(level+1,W_left,itemLeft,0);
}

}

void solve(){
cin>>n>>k;
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
dp.assign(n+1, vector<vector<vector<int>>>(w+1,vector<vector<int>>(k+1,vector<int>(2,-1))));
cout<<rec(0,w,k,0)<<endl;
generate(0,w,k,0);
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
