#include <iostream>
#include <string>
#include <cstring>
using namespace std;
/***
    滑动窗口问题：
    Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
*/
class Solution {
public:
    string minWindow(string s, string t) {
        int table[128];
        memset(table,0,sizeof(table));
        for(int i = 0 ; i < t.length(); i++){
            table[t[i]]++;
        }
        int left = 0 , right = 0 , count = t.length();
        int startIdx = 0 , minLen = INT_MAX;
        while(right < s.length()){
            if(table[s[right++]]-- > 0) count--;//窗口右端不断增大
            while(count == 0){//循环内不断缩小左端
                if(table[s[left++]]++ >= 0) count++;
                if(right - left + 1 < minLen){
                    minLen = right - left +1 ;
                    startIdx = left - 1;
                }
            }
        }
        return minLen == INT_MAX ? "" : s.substr(startIdx , minLen);
    }
};
int main()
{
    Solution s;
    cout<<s.minWindow("ADOBECODEBANC","ABC");
    return 0;
}
