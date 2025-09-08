#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n;
vector<int> dp;
vector<int> arr;

int rec(int level){
    if(level<0)return 0;
    if(dp[level]!=-1)return dp[level];
    int best = 1;
    for(int prev_taken=0;prev_taken<level;prev_taken++){
        if(arr[prev_taken]<arr[level]){
            best = max(best,1+rec(prev_taken));
        }
    }
    return dp[level] = best;
}

vector<int> generate(int level){
    vector<int> path;
    path.push_back(level);
    int need = dp[level]-1;
    for(int prev=level-1;prev>=0;prev--){
        if(arr[prev]<arr[level] && dp[prev]==need){
            vector<int> temp = generate(prev);
            for(auto &x:temp) path.push_back(x);
            break;
        }
    }
    return path;
}

void solve(){
    cin>>n;
    arr.assign(n,0);
    dp.assign(n,-1);
    for(int i=0;i<n;i++)cin>>arr[i];

    int ans = 0;
    int last = -1;
    for(int i=0;i<n;i++){
        int val = rec(i);
        if(val>ans){
            ans = val;
            last = i;
        }
    }

    cout<<ans<<endl;

    vector<int> lis = generate(last);
    reverse(lis.begin(),lis.end());
    for(auto &x:lis)cout<<x<<" ";
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
