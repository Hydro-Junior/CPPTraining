#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
using namespace std;
/**
    不重复排列问题，
    （1）初始方法：利用dp插入，结合去重实现，方法不是很好，但一时没有巧妙的思路。
    （2）超棒的递归实现!基于交换，仅仅20行不到。核心思路很简单：对每个位作交换，同样的数字只交换一次到该位
*/
void printVec(vector<int>& vec){
    int sz = vec.size();
    for(int i = 0; i < sz; i++){
        if(i != 0) cout<<" "<<vec[i];
        else cout<<vec[i];
    }
    cout<<endl;
}
typedef vector<vector<int>>::iterator vit;
typedef list<int>::iterator lit;
/*class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int>> res;
        vector<int> sub;
        sort(nums.begin(),nums.end());
        sub.push_back(nums[0]);
        res.push_back(sub);
        for(int i = 1 ;  i < nums.size(); i++){
            int k = nums[i];
            vector<vector<int>> tpres;
            for(vector<int> vec : res){
                for(int pos = 0; pos <= vec.size(); pos++){
                    while(pos < vec.size() && vec[pos] == k) pos++;//找到插入位置
                    list<int> ls(vec.begin(),vec.end());
                    lit it = ls.begin();
                    for(int j = pos; j > 0; j--){
                        it++;
                    }
                    ls.insert(it,k);
                    vector<int> v(ls.begin(),ls.end());
                    tpres.push_back(v);
                }
            }
            res.swap(tpres);
        }
        sort(res.begin(),res.end());
        vit nend= unique(res.begin(),res.end());
        res.erase(nend,res.end());
        return res;
    }
};*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(),nums.end());
        permute(res,nums,0,nums.size());
        return res;
    }
    void permute(vector<vector<int>>& res,vector<int> nums,int i,int j){//特别注意这里的nums不能带引用号，必须是副本，不然改的一直是同一个nums
        if(i == j-1) {
           res.push_back(nums);
           return;
        }
        for(int k = i ; k < j ;k ++){
            if(k != i && nums[k] == nums[i]) continue;//原来的排列算一种，其他重复数字的跳过
            swap(nums[k],nums[i]);//定好了第i位的一种情况
            permute(res,nums,i+1,j);//考虑下一位，按每一位讨论进行递归处理才是思考这个问题的关键
        }
    }
};
int main()
{
    int input[] = {2,2,1,1};
    vector<int> vec(input,input+4);
    Solution s;
    vector<vector<int> > res =  s.permuteUnique(vec);
    for(vector<int> vec : res){
        printVec(vec);
    }
    return 0;
}
