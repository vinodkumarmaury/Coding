#include<bits/stdc++.h>
using namespace std;


int main(){
     int n,m;
     cin>>n>>m;
     vector<vector<int>> g(n+1);
     vector<int> indegree(n+1,0);
     for(int i = 0;i<m;i++){
          int a,b;
          cin>>a>>b;
          indegree[b]++;
          g[a].push_back(b);
     }
 
     queue<int> q;
     vector<int> topo;
     for(int i = 1;i<=n;i++){
          if(indegree[i]==0){
               q.push(i);
          }
     }
 
     while(!q.empty()){
          int node = q.front();
          q.pop();
          topo.push_back(node);
          for(auto &v:g[node]){
               indegree[v]--;
               if(indegree[v]==0){
                    q.push(v);
               }
          }
     }
     if(topo.size()!=n){
          cout<<"IMPOSSIBLE"<<endl;
          return 0;
     }
 for(auto &x:topo)cout<<x<<" ";
 cout<<endl;

     return 0;
}

