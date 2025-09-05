#include<bits/stdc++.h>
using namespace std;

int n,k;
string s;

int dp[501][4][4][501];
int rec(int i,int last,int first,int aleft){
    // pruning 
    if(aleft<0)return 0;
    // basecase
    if(i==n){
        if(last==first){
            return 0;
        }else{
            return 1;
        }
    }
    // cache check
    if(last!=-1 && dp[i][last][first][aleft]!=-1){
        return dp[i][last][first][aleft];
    }
    // transition
    int ans = 0;
    if(s[i]=='?'){
        for(int ch=0;ch<=3;ch++){
            if(ch==last)continue;
            if(i==0){
                ans+= rec(i+1,ch,ch,aleft-(ch==0?1:0));
            }else{
                ans+= rec(i+1,ch,first,aleft-(ch==0?1:0));
            }
        }
    }else if((s[i]-'A')==last){
        ans = 0;
    }else{
        int ch = s[i]-'A';
        if(i==0){
            ans+= rec(i+1,ch,ch,aleft-(ch==0?1:0));
        }else{
            ans+= rec(i+1,ch,first,aleft-(ch==0?1:0));
        }
    }
    // save and return
    if(last!=-1)dp[i][last][first][aleft] = ans;
    return ans;
}

string ans;
void generate(int i,int last,int first,int aleft){
    // basecase
    if(i==n){
        return;
    }

    // transition
    if(s[i]=='?'){
        for(int ch=0;ch<=3;ch++){
            if(ch==last)continue;
            if(i==0){
                if(rec(i+1,ch,ch,aleft-(ch==0?1:0))>0){
                    ans += char('A'+ch);
                    generate(i+1,ch,ch,aleft-(ch==0?1:0));
                    return;
                }
            }else{
                if(rec(i+1,ch,first,aleft-(ch==0?1:0))>0){
                    ans += char('A'+ch);
                    generate(i+1,ch,first,aleft-(ch==0?1:0));
                    return;
                }
            }
        }
    }else if((s[i]-'A')==last){
        // non reachable...
        // assert(1==0);
    }else{
        int ch = s[i]-'A';
        ans += s[i];
        if(i==0){
            generate(i+1,ch,ch,aleft-(ch==0?1:0));
        }else{
            generate(i+1,ch,first,aleft-(ch==0?1:0));
        }
    }
}


void solve(){
    cin>>n>>k;
    cin>>s;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,-1,-1,k)<<endl;
    generate(0,-1,-1,k);
        cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}