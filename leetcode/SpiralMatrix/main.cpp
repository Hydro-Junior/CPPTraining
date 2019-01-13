#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size()==0) return res;
        putItems(res, matrix, 0, matrix.size()-1, 0, matrix[0].size()-1);
        return res;
    }
    void putItems(vector<int>& res,vector<vector<int>>& matrix,int rs, int re, int cs, int ce){
        if(rs > re || cs > ce) return;
        for(int i = cs ; i <= ce; i++){
            res.push_back(matrix[rs][i]);
        }
        if(rs == re) return;
        for(int i = rs + 1; i <= re; i++){
            res.push_back(matrix[i][ce]);
        }
        if(cs == ce) return;
        for(int i = ce - 1; i >= cs; i--){
            res.push_back(matrix[re][i]);
        }
        for(int i = re-1; i > rs; i--){
            res.push_back(matrix[i][cs]);
        }
        cout<<endl;
        putItems(res,matrix,rs + 1, re - 1, cs +1 , ce -1);
    }
};
int main()
{
    Solution s;
    vector<vector<int> > res;
    int a1[4] = {1,2,3,4};
    int a2[] = {5,6,7,8};
    int a3[] = {9,10,11,12};
    vector<int> v1(a1,a1+4);
    vector<int> v2(a2,a2+4);
    vector<int> v3(a3,a3+4);
    res.push_back(v1);
    res.push_back(v2);
    res.push_back(v3);
    vector<int> vec = s.spiralOrder(res);
    for(int item : vec){
        cout<<item<<" ";
    }
    return 0;
}
