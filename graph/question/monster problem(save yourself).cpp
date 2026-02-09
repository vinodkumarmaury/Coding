// Description
// You and some monsters are in a matrix. When taking a step to some direction in the matrix, each monster may simultaneously take one as well. Your goal is to reach one of the boundary squares without ever sharing a square with a monster.

// Your task is to find out if your goal is possible, and if it is, print the shortest length of the path that you can follow. Your plan has to work in any situation; even if the monsters know your path beforehand.

// Input Format
// The first input line has two integers 
// n
// n and 
// m
// m: the height and width of the matrix.
// After this, there are 
// n
// n lines of 
// m
// m characters describing the matrix. Each character is . (floor), # (wall), A (start), or M (monster). There is exactly one A in the input.

// Output Format
// First, print "YES" if your goal is possible, and "NO" otherwise.
// If your goal is possible, also print the length of the shortest path that you'll follow.

// Constraints
// 1
// ≤
// n
// ,
// m
// ≤
// 1000
// 1≤n,m≤1000

// Sample Input 1
// 5 8
// ########
// #M..A..#
// #.#.M#.#
// #M#..#..
// #.######
// Sample Output 1
// YES
// 5
// Sample Input 2
// 1 3
// ##A
// Sample Output 2
// YES
// 0
// Sample Input 3
// 3 3
// ###
// #A#
// #M.
// Sample Output 3
// NO
// Note
// For the first sample, the person can reach a boundary cell in 
// 5
// 5 steps before any monster can reach that cell. For the second sample, the person is enclosed by walls and cannot reach any boundary. For the third sample, the person is already on a boundary cell, so the shortest path length is 
// 0
// 0.

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
const int inf = 1e9;

void solve(){
int n,m;
cin>>n>>m;
vector<vector<char>> mat(n,vector<char>(m));
queue<pair<int,int>> monster;
queue<pair<int,int>> person;
vector<vector<int>> dist_monster(n,vector<int>(m,inf));
vector<vector<int>> dist_person(n,vector<int>(m,inf));
vector<pair<int,int>> exit;
for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
        cin>>mat[i][j];
        if(mat[i][j]=='A'){
            person.push({i,j});
            dist_person[i][j] = 0;
             if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                cout << "YES" << endl;
                cout << 0 << endl;
                return;
            }
        }
        else if(mat[i][j]=='M'){
            monster.push({i,j});
            dist_monster[i][j] = 0;
        }
        else if(i==n-1||i==0||j==m-1||j==0){
            exit.push_back({i,j});
        }
    }
}


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

while(!person.empty()){
    auto curr = person.front();
    person.pop();
    for(int k = 0;k<4;k++){
        int x = curr.first+dx[k];
        int y = curr.second+dy[k];
        if(x>=0&&y>=0&&x<n&&y<m&&mat[x][y]!='#'){
            if(dist_person[x][y]>dist_person[curr.first][curr.second]+1){
                dist_person[x][y] = dist_person[curr.first][curr.second]+1;
                person.push({x,y});
            }
        }
    }
}

while(!monster.empty()){
    auto curr = monster.front();
    monster.pop();
    for(int k = 0;k<4;k++){
        int x = curr.first+dx[k];
        int y = curr.second+dy[k];
        if(x>=0&&y>=0&&x<n&&y<m&&mat[x][y]!='#'){
            if(dist_monster[x][y]>dist_monster[curr.first][curr.second]+1){
                dist_monster[x][y] = dist_monster[curr.first][curr.second]+1;
                monster.push({x,y});
            }
        }
    }
}

for(auto &ex:exit){
    int x = ex.first;
    int y = ex.second;
    if(dist_monster[x][y]>dist_person[x][y]){
        cout<<"YES"<<endl;
        cout<<dist_person[x][y]<<endl;
        return;
    }
}

    cout << "NO" << endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}



