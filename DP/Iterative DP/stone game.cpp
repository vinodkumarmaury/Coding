// Two players alternately remove stones from two boxes.
// In one move, a player can remove any number of stones from one box **or** the same number from both boxes.
// The player who cannot move (both boxes empty) **loses** — determine if the first player wins given **x** and **y**.


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp,dp1;

int x,y;

int rec(int i,int j){
    if(i==0&&j==0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans = 0;
    for(int z = 0;z<i;z++){
        if(rec(z,j)==0){
            ans = 1;
            break;
        }
    }
    for(int z = 0;z<j;z++){
        if(rec(i,z)==0){
            ans = 1;
            break;
        }
    }
    for(int z = 1;z<=min(i,j);z++){
        if(rec(i-z,j-z)==0){
            ans = 1;
            break;
        }
    }
    return dp[i][j] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
    cin>>x>>y;
    dp.assign(x+1,vector<int>(y+1,-1));
    dp1.assign(x+1,vector<int>(y+1,-1));
    cout<<(rec(x,y)==1?"YES":"NO")<<endl;
    // Iterative solution
    cout<<"Iterative Solution"<<endl;
    for(int i = 0;i<=x;i++){
        for(int j = 0;j<=y;j++){
            if(i==0&&j==0){
                dp1[i][j] = 0;
            }
            int ans = 0;
            for(int z = 0;z<i;z++){
                if(dp1[z][j]==0){
                    ans = 1;
                    break;
                }
            }
            for(int z = 0;z<j;z++){
                if(dp1[i][z]==0){
                    ans = 1;
                    break;
                }
            }
            for(int z = 1;z<=min(i,j);z++){
                if(dp1[i-z][j-z]==0){
                    ans = 1;
                    break;
                }
            }
        dp1[i][j] = ans;
        }
    }
    cout<<(dp1[x][y]==1?"YES":"NO")<<endl;
    }
    return 0;
}


