#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n;
vector<int> arr;
vector<vector<vector<int>>> dp;   // for best length
vector<vector<vector<int>>> cnt;  // for number of subsequences

int rec(int level,int last,int phase){
    // base case
    if(level==n){
        return 0;
    }
    // cache check
    if(dp[level][last][phase]!=-1){
        return dp[level][last][phase];
    }

    int best = rec(level+1,last,phase); // not take
    int ways = cnt[level+1][last][phase]; // ways for that best

    // take
    if(phase==0){
        if(arr[level]>last){
            int tmp = 1+rec(level+1,arr[level],0);
            if(tmp > best){
                best = tmp;
                ways = cnt[level+1][arr[level]][0];
            }else if(tmp == best){
                ways = (ways + cnt[level+1][arr[level]][0])%mod;
            }
        }else if(arr[level]<last){
            int tmp = 1+rec(level+1,arr[level],1);
            if(tmp > best){
                best = tmp;
                ways = cnt[level+1][arr[level]][1];
            }else if(tmp == best){
                ways = (ways + cnt[level+1][arr[level]][1])%mod;
            }
        }
    }else{
        if(arr[level]<last){
            int tmp = 1+rec(level+1,arr[level],1);
            if(tmp > best){
                best = tmp;
                ways = cnt[level+1][arr[level]][1];
            }else if(tmp == best){
                ways = (ways + cnt[level+1][arr[level]][1])%mod;
            }
        }
    }

    dp[level][last][phase] = best;
    cnt[level][last][phase] = ways;
    return best;
}

void solve(){
    cin>>n;
    arr.assign(n+1,0);
    dp.assign(n+1,vector<vector<int>>(101,vector<int>(2,-1)));
    cnt.assign(n+1,vector<vector<int>>(101,vector<int>(2,0)));

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // base case initialization
    for(int last=0;last<=100;last++){
        for(int p=0;p<2;p++){
            cnt[n][last][p] = 1; // exactly one empty subsequence
        }
    }

    int ans = rec(0,0,0);
    int freq = cnt[0][0][0];

    cout<<ans<<" "<<freq<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
