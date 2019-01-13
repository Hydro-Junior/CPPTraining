#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = 0, mask = 0;
        for(int i = 30 ; i >= 0; i--){
            mask |= (1<<i);
            unordered_set<int> nset;
            for(int n : nums){
                nset.insert(mask & n);
            }
            int tmp = max | (1<<i);
            for(int pre : nset){
                if(nset.find(pre ^ tmp) != nset.end()){
                    max = tmp;
                    break;
                }
            }
        }
        return max;
    }
};
int main()
{
    Solution s;
    int a[] = {3, 10, 5, 25, 2, 8};
    vector<int> v(a,a+5);
    int res= s.findMaximumXOR(v);
    cout << res << endl;
    return 0;
}
