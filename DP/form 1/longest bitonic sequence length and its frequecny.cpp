#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n;
vector<int> arr;
vector<vector<vector<pair<int,int>>>>dp;

pair<int,int> remax(pair<int,int> ans,pair<int,int> possible){
    possible.first+=1;
    if(possible.first>ans.first){
        ans = possible;
    }
    else if(possible.first==ans.first){
        ans.second+=possible.second;
    }
    return ans;
}

pair<int,int> rec(int level,int last,int phase){
    // base case
    if(level==n){
        return {0,1};
    }
   // cache check
    if(dp[level][last][phase]!=make_pair(-1,-1)){
        return dp[level][last][phase];
    }
    // compute
    // Not take
    pair<int,int> ans = rec(level+1,last,phase);
    // take
        if(phase==0){
            if(arr[level]>last){
            ans = remax(ans,rec(level+1,arr[level],0));
            }
            else if(arr[level]<last){
            ans = remax(ans,rec(level+1,arr[level],1));  
            }
        }
        else{
            if(arr[level]>last){
             ///
            }
            else if(arr[level]<last){
            ans = remax(ans,rec(level+1,arr[level],1));
            }
        }
    return dp[level][last][phase] = ans;
}

void solve(){
cin>>n;
arr.assign(n+1,0);
dp.assign(n+1,vector<vector<pair<int,int>>>(101,vector<pair<int,int>>(2,make_pair(-1,-1))));
for(int i = 0;i<n;i++){
    cin>>arr[i];
}

auto it = rec(0,0,0);
cout<<it.first<<" "<<it.second<<endl;
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