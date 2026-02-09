// Edge Removals Problem:
// Given an undirected graph G with N nodes (1…N) and M edges (1…M). There are Q queries of two types:
// 1 X — remove edge X.
// 2 — print the current number of connected components.
// Edges are 1-indexed; multiple removals of the same edge consider only the last one. No self-loops or multiple edges.
// Input:
// Line 1: N M Q
// Next M lines: u v (edge u–v)
// Next Q lines: queries (1 X or 2)
// Output:
// For each type 2 query, print the number of connected components.
// Constraints:
// 1 ≤ N, M, Q ≤ 10⁵
// 1 ≤ u, v ≤ N
// Example:
// Input:
// 3 3 5
// 1 2
// 2 3
// 3 1
// 2
// 1 2
// 2
// 1 1
// 2
// Output:
// 1
// 1
// 2
// Explanation:
// Initially connected. Removing edge 2 keeps the graph connected. Removing edge 1 isolates node 2, yielding 2 components {2}, {1,3}.

#include<bits/stdc++.h>
using namespace std;

// we will start adding edge in reverse order instead of removing and will find no component  

struct UnionFind{
         vector<int> par,rank;
         int set_size; // #ofcc
         int n;
         UnionFind(int a){ // initialization
            set_size=n=a;
            par.resize(n+1);
            rank.assign(n+1,1);
            for(int i=1; i<=n; i++)par[i]=i;
         }
         int find(int x){
               if(par[x]==x)return x;
               else return par[x]=find(par[x]);
         }
         void merge(int x, int y){
              x=find(x);
              y=find(y);
              if(x==y)return;
              if(rank[x]<rank[y]){
                   rank[y]+=rank[x];
                   par[x]=y;
              }
              else{
                rank[x]+=rank[y];
                par[y]=x;
              }
              set_size--;
         }
         void reset(){
            for(int i=1; i<=n; i++)par[i]=i;
            rank.assign(n+1,1);
            set_size=n;
         }

        int size(){
            return set_size;
        }
        void print(){
            for(int i = 1;i<=n;i++){
                cout<<i<<"->"<<par[i]<<endl;
            }
        }

};


int main(){
    int n,m,q;
    cin>>n>>m>>q;
    UnionFind uf(n);
    vector<pair<int,int>> edges(m+1);
    for(int i = 1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        edges[i] = {a,b};
    }
     vector<pair<int,int>> query;
     vector<bool> deleted(m+1,false);
     while(q--){
      int y;
      cin>>y;
      if(y==2){
        query.push_back({y,-1});
      }
      else{
       int x;
       cin>>x;
       query.push_back({y,x});
       deleted[x] = true;
      }
     }
    
    for(int i=1;i<=m;i++) {
        if(!deleted[i]) uf.merge(edges[i].first, edges[i].second);
    }

    vector<int> ans;

    for(int i = query.size()-1;i>=0;i--){
        if(query[i].first==2){
            ans.push_back(uf.size());
        }
        else{
          int x = query[i].second;
          uf.merge(edges[x].first,edges[x].second);
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto x : ans) cout << x << '\n';
}






