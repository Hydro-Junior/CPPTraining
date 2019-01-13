#include<iostream>
#include<sstream>
#include<unordered_map>
using namespace std;
static int n = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
int main(){
    unordered_map<int,string> mp;
    int res[55],sfSeq[55],copy[55];
    string S[14],H[14],C[14],D[14],tmp;
    for(int i = 1 ; i <= 13; i++){
        stringstream ss;
        ss<<i;ss>>tmp;
        S[i] = "S"+tmp; mp[i] = S[i];
        H[i] = "H"+tmp; mp[i+13] = H[i];
        C[i] = "C"+tmp; mp[i+26] = C[i];
        D[i] = "D"+tmp; mp[i+39] = D[i];
    }
    mp[53] = "J1"; mp[54] = "J2";
    int shuffleNum;
    cin>>shuffleNum;
    for(int i = 1; i <= 54; i++){
        copy[i] = i;
        res[i] = i;
        cin>>sfSeq[i];
    }
    while(shuffleNum--){
        for(int i = 1; i <= 54; i++){
            res[sfSeq[i]] = copy[i];
        }
        for(int i = 1; i <= 54; i++){
            copy[i] = res[i];
        }
    }
    for(int i = 1; i <=54; i++){
        if(i != 1) cout<<" "<<mp[res[i]];
        else cout<<mp[res[i]];
    }
    return 0;
}
