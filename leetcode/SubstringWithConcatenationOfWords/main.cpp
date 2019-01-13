#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
using namespace std;
/**
    寻找相同长度的给定字符串构成的窗口，假如每个字符串长度为len，只需检测len个长窗口即可！
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int N = s.size(), M = words.size();
        if(M <= 0 || N <= 0) return res;
        int len = words[0].size(),cnt;

        unordered_map<string,int> smap,tmap;

        for(string word : words){
            smap[word]++;
        }
        for(int i = 0 ; i < len; i++){//长窗口只有len种可能，len为每个单词的长度，这很重要（起始位置除以len的所有可能余数！）
            tmap.clear();
            int lo = i;
            cnt = 0;
            //任何问题都不需要记什么模板，这不是一个算法学习者的好习惯，包括滑动窗口
            //只需在脑内形成动画，一端不断增长，同时循环地不断缩小另一端。
            for(int j = i ; j + len <= N; j += len){
                string str = s.substr(j,len);
                if(smap.find(str) == smap.end()){
                    tmap.clear();
                    lo = j + len;
                    cnt = 0;
                }else{
                    if(++tmap[str] <= smap[str]){ cnt ++; }
                    while(tmap[str] > smap[str]){
                        string sub = s.substr(lo,len);
                        if(--tmap[sub] < smap[sub]) cnt--;
                        lo += len;
                    }
                    if(cnt == M) res.push_back(lo);
                }
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    string text = "aaaabbbbccaaaa";
    vector<string> words;
    words.push_back("aa");
    words.push_back("aa");
    words.push_back("bb");
    words.push_back("cc");
    vector<int> res = s.findSubstring(text,words);
    for(vector<int>::iterator it= res.begin(); it != res.end(); it++){
        cout<<*it<<" ";
    }
    return 0;
}
