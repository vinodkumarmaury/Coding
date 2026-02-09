#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n,k;
string s;
int dp[501][4][4][501];

int rec(int level, int last,int first,int Aleft){
    // prune
     if(Aleft<0)return 0;
    // base case
     if(level==n){
        return (first != last)&&Aleft>=0;
     }
    // cache check
    if(last!=-1&&dp[level][last][first][Aleft]!=-1){
        return dp[level][last][first][Aleft];
    }
    // transaction
    
    int ans = 0;

    if(s[level]=='?'){
        if(level==0){
        for(int ch = 0;ch<4;ch++){
            ans+=rec(level+1,ch,ch,Aleft-(ch==0?1:0));
        }
        }
        else{
            for(int ch = 0;ch<4;ch++){
                if(ch==last)continue;
                ans+=rec(level+1,ch,first,Aleft-(ch==0?1:0));
            }
        }
        }

       else{
        if(s[level]-'A'==last){

        }
        else{
            int ch = s[level]-'A';
            if(level==0){
                ans+=rec(level+1,ch,ch,Aleft-(ch==0?1:0));
            }
            else{
                ans+=rec(level+1,ch,first,Aleft-(ch==0?1:0));
            }
        }
    }
    // save and return
    if(last !=-1){
        return dp[level][last][first][Aleft] = ans;
    }
    else{
        return ans;
    }
}

void solve(){
cin>>n>>k;
cin>>s;
memset(dp,-1,sizeof(dp));
cout<<rec(0,-1,-1,k);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}