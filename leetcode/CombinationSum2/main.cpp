#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
/**
    �ø����ļ������ճ�Ŀ��������Ϸ�ʽ�����ظ���
    1. ����01����˼���vectorȥ�أ���������õķ�������ʱ�벻�����õ�ȥ�ؼ��ɡ�
    2. �����ʵĻ��ݷ����Ƽ�https://leetcode.com/problems/combination-sum/discuss/16502/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning)��
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
            combine(res,cds,vec,i+1,target-cds[i]);//���������Ϊʲô��i+1,��������ظ�ʹ��Ԫ�صĻ���i��not i + 1 because we can reuse same elements������ע�͵�if��伴�ɣ���
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
