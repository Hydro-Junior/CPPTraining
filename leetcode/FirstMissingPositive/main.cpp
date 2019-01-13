#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int k = partition(nums);//下标范围定为【0，k-1】，共k个数
        for(int i = 0 ; i < k; i++){
            if(abs(nums[i]) <= k){
                nums[k-1] = nums[k-1]<0?nums[k-1]:-nums[k-1];
            }
        }
        for(int i = 0 ;i < k; i++){
            if(nums[i] > 0){
                return i+1;
            }
        }
        return k+1;
    }
    int partition(vector<int>& nums){
        int i = 0, j = nums.size()-1;
        while(i <= j){
            if(nums[i] <= 0){
                swap(nums[i],nums[j--]);
            }else{
                i++;
            }
        }
        return i;//返回有效的数字个数
    }
};
int main()
{
    Solution s;
    int input[] = {1,2,0};
    vector<int> v(input,input+3);
    cout<<s.firstMissingPositive(v)<<endl;
    return 0;
}
