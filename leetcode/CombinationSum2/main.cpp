#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
/**
    用给定的几个数凑成目标数的组合方式（不重复）
    1. 尝试01背包思想加vector去重，但不是最好的方法，暂时想不到更好的去重技巧。
    2. 更精彩的回溯法（推荐https://leetcode.com/problems/combination-sum/discuss/16502/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning)）
*/
void printVec(vector<int>& vec){
    int sz = vec.size();
    for(int i = 0; i < sz; i++){
        if(i != 0) cout<<" "<<vec[i];
        else cout<<vec[i];
    }
    cout<<endl;
}
/*
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res[target+1];
        sort(candidates.begin(),candidates.end());
        for(int cd : candidates){
            for(int k = target; k >= 1; k--){
                if(k > cd && res[k-cd].size()){
                    vector<vector<int>> tmp = res[k-cd];
                    for(vector<int> v : tmp){
                        v.push_back(cd);
                        res[k].push_back(v);
                    }
                }else if(k - cd == 0){
                    vector<int> tmp;
                    tmp.push_back(cd);
                    res[k].push_back(tmp);
                }
            }
        }
        sort(res[target].begin(),res[target].end());
        vector<vector<int>>::iterator nend = unique(res[target].begin(),res[target].end());
        res[target].erase(nend,res[target].end());
        return res[target];
    }
};*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& cds, int target) {
        vector<vector<int>> res;
        vector<int> vec;
        sort(cds.begin(),cds.end());
        combine(res,cds,vec,0,target);
        return res;
    }
    void combine(vector<vector<int>>& res,vector<int>& cds,vector<int>& vec,int begin,int target){
        if(target == 0){
            res.push_back(vec);
            return;
        }
        if(target < 0) return;
        for(int i = begin ; i < cds.size() && target >= cds[i]; i++){
            if(i > begin && cds[i]== cds[i-1]) continue;
            vec.push_back(cds[i]);
            combine(res,cds,vec,i+1,target-cds[i]);//想清楚这里为什么是i+1,如果允许重复使用元素的话是i（not i + 1 because we can reuse same elements，并且注释掉if语句即可）！
            vec.pop_back();
        }
    }
};
int main()
{
    int input[] = {4,4,2,1,4,2,2,1,3};
    vector<int> vec(input,input+9);
    Solution s;
    vector<vector<int> > res =  s.combinationSum2(vec, 6);
    for(vector<int> vs : res){
        printVec(vs);
    }
    return 0;
}
