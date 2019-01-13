#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
using namespace std;
/**
    Ѱ����ͬ���ȵĸ����ַ������ɵĴ��ڣ�����ÿ���ַ�������Ϊlen��ֻ����len�������ڼ��ɣ�
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
        for(int i = 0 ; i < len; i++){//������ֻ��len�ֿ��ܣ�lenΪÿ�����ʵĳ��ȣ������Ҫ����ʼλ�ó���len�����п�����������
            tmap.clear();
            int lo = i;
            cnt = 0;
            //�κ����ⶼ����Ҫ��ʲôģ�壬�ⲻ��һ���㷨ѧϰ�ߵĺ�ϰ�ߣ�������������
            //ֻ���������γɶ�����һ�˲���������ͬʱѭ���ز�����С��һ�ˡ�
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
