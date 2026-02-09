#include<bits/stdc++.h>
using namespace std;

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


int main() {
    // Example: 5 nodes (1..5)
    UnionFind uf(5);

    cout << "Initially, #components = " << uf.size() << "\n";

    // Merge some sets
    uf.merge(1,2);
    cout << "After merge(1,2), #components = " << uf.size() << "\n";

    uf.merge(3,4);
    cout << "After merge(3,4), #components = " << uf.size() << "\n";

    uf.merge(2,3);
    cout << "After merge(2,3), #components = " << uf.size() << "\n";

    // Test finds
    cout << "Find(1) = " << uf.find(1) << "\n";
    cout << "Find(4) = " << uf.find(4) << "\n";
    cout << "Find(5) = " << uf.find(5) << "\n";

    // Print parent structure
    uf.print();

    // Reset and test again
    uf.reset();
    cout << "After reset, #components = " << uf.size() << "\n";
    uf.print();

    return 0;
}




