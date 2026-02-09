#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<int> computePrefixFunction(string pattern) {
    int m = pattern.length();
    vector<int> kmp(m+1);
    kmp[0] = -1;
   int i = 0,j = -1;
   while(i<m){
    while(j!=-1&&pattern[i]!=pattern[j])j = kmp[j];
    j++;i++;
    kmp[i] = j;
   }
    return kmp;
}

void KMP(string S, string W) {
    int n = S.length(), m = W.length();
    vector<int> kmp = computePrefixFunction(W);
    cout<<endl;
   int i = 0,j=0;
   while(i<n){
    while(j!=-1&&(j==m||W[j]!=S[i]))j =kmp[j];
    i++;j++;
    if(j==m){
        cout<<"Pattern occurs with shift "<<(i-m)<<endl;
        j = kmp[j];
    }
   }
}

int main() {
    string S = "ABABDABACDABABCABAB";
    string W = "ABABCABAB";
    KMP(S, W);
    return 0;
}