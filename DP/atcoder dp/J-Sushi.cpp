#include<bits/stdc++.h>
using namespace std;
  int n;
  
double dp[302][302][302];
int vis[302][302][302];

  double rec(int c1,int c2,int c3){
    if (c1 < 0 || c2 < 0 || c3 < 0) return 0.0;
    if (c1 == 0 && c2 == 0 && c3 == 0) return 0.0;
    if (vis[c1][c2][c3]) return dp[c1][c2][c3];
    vis[c1][c2][c3] = 1;
    int total = c1+c2+c3;
    double expal = (double)n/total;
    if(c1>0)expal+=((double)c1/total)*rec(c1-1,c2,c3);
    if(c2>0)expal+=((double)c2/total)*rec(c1+1,c2-1,c3);
    if(c3>0)expal+=((double)c3/total)*rec(c1,c2+1,c3-1);
    return dp[c1][c2][c3] = expal;
  }
  
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  int c1 = 0,c2 = 0,c3 = 0;
  for(int i = 0;i<n;i++){
    int x;
    cin>>x;
    if(x==1)c1++;
    else if(x==2)c2++;
    else c3++;
  }
  cout<<fixed<<setprecision(10)<<rec(c1,c2,c3)<<endl;
  return 0;
}