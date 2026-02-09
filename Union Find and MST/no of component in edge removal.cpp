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
    int n;
    cin>>n;
    UnionFind uf(n);
    vector<pair<int,int>> v;
    for(int i = 0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    reverse(v.begin(),v.end());
for (int i = 0; i < n; i++) {
    cout << "Before merge(" << v[i].first << "," << v[i].second << ")"
         << ", #components = " << uf.size() << "\n";

    uf.merge(v[i].first, v[i].second);

    cout << "After merge(" << v[i].first << "," << v[i].second << ")"
         << ", #components = " << uf.size() << "\n";
}

}
