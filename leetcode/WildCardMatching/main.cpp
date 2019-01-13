#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        bool dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        dp[0][0] = true;
        int k = 1;
        while(m >= k && p[k-1]=='*'){
            dp[k++][0] = true;
        }
        for(int i = 1 ; i <= m ; i++){
            for(int j = 1; j <= n; j++){
                if(p[i-1] == '*'){
                    dp[i][j] = dp[i][j-1] || dp[i-1][j-1] || dp[i-1][j];
                }else if(p[i-1] == '?' || p[i-1] == s[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                   dp[i][j] = false;
                }
            }
        }
        return dp[m][n];
    }
};
int main()
{
    Solution slt;
    string s = "ho";
    string p = "**ho";
    cout<<slt.isMatch(s,p);
    return 0;
}
