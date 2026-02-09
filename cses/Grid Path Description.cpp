#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int n;
string s;

int rec(int i,int j,int id,vector<vector<int>> &mat){
   if(i>6||j>6||i<0||j<0)return 0;
    if(i==6 && j==0){ 
        return id==n;
    }

    if((i==0 || mat[i-1][j]) && (i==6 || mat[i+1][j]) &&
       j>0 && j<6 && !mat[i][j-1] && !mat[i][j+1]) return 0;

    if((j==0 || mat[i][j-1]) && (j==6 || mat[i][j+1]) &&
       i>0 && i<6 && !mat[i-1][j] && !mat[i+1][j]) return 0;
    int ans = 0;
    if(s[id]=='?'){
        if(i>0&&!mat[i-1][j]){  //U
            mat[i-1][j] = 1;
            ans+=rec(i-1,j,id+1,mat);
            mat[i-1][j] = 0;
        }
        if(j>0&&!mat[i][j-1]){ //L
            mat[i][j-1] = 1;
            ans+=rec(i,j-1,id+1,mat);
            mat[i][j-1] = 0;
        }
        if(i<6&&!mat[i+1][j]){//D
            mat[i+1][j] = 1;
            ans+=rec(i+1,j,id+1,mat);
            mat[i+1][j] = 0;
        }
        if(j<6&&!mat[i][j+1]){ // R
            mat[i][j+1] = 1;
            ans+=rec(i,j+1,id+1,mat);
            mat[i][j+1] = 0;
        }
    }
    else if(s[id]=='U'){
        if(i>0&&!mat[i-1][j]){
         mat[i-1][j] = 1;
         ans+=rec(i-1,j,id+1,mat);
         mat[i-1][j] = 0;
        }
        else{
            return 0;
        }
    }
    else if(s[id]=='R'){
        if(j<6&&!mat[i][j+1]){
         mat[i][j+1] = 1;
         ans+=rec(i,j+1,id+1,mat);
         mat[i][j+1] = 0;
        }
        else{
            return 0;
        }
    }
    else if(s[id]=='D'){
        if(i<6&&!mat[i+1][j]){
         mat[i+1][j] = 1;
         ans+=rec(i+1,j,id+1,mat);
         mat[i+1][j] = 0;;
        }
        else{
            return 0;
        }
    }
    else if(s[id]=='L'){
        if(j>0&&!mat[i][j-1]){
         mat[i][j-1] = 1;
         ans+=rec(i,j-1,id+1,mat);
         mat[i][j-1] = 0;
        }
        else{
            return 0;
        }
    }
    return ans;
}

void solve(){
    cin>>s;
    n = s.length();
    vector<vector<int>> mat(7,vector<int>(7,0));
    mat[0][0] = 1;
    cout<<rec(0,0,0,mat)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}