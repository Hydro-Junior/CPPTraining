#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
using namespace std;
/**
    ���ظ��������⣬
    ��1����ʼ����������dp���룬���ȥ��ʵ�֣��������Ǻܺã���һʱû�������˼·��
    ��2�������ĵݹ�ʵ��!���ڽ���������20�в���������˼·�ܼ򵥣���ÿ��λ��������ͬ��������ֻ����һ�ε���λ
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
                    while(pos < vec.size() && vec[pos] == k) pos++;//�ҵ�����λ��
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
    void permute(vector<vector<int>>& res,vector<int> nums,int i,int j){//�ر�ע�������nums���ܴ����úţ������Ǹ�������Ȼ�ĵ�һֱ��ͬһ��nums
        if(i == j-1) {
           res.push_back(nums);
           return;
        }
        for(int k = i ; k < j ;k ++){
            if(k != i && nums[k] == nums[i]) continue;//ԭ����������һ�֣������ظ����ֵ�����
            swap(nums[k],nums[i]);//�����˵�iλ��һ�����
            permute(res,nums,i+1,j);//������һλ����ÿһλ���۽��еݹ鴦�����˼���������Ĺؼ�
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
