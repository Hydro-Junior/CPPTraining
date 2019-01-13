#include <iostream>
#include <vector>
using namespace std;
//̰�Ľ�Ϲ��ѵ�˼��
static int n = []() {
    ios::sync_with_stdio(false);//���ͬ����
    cin.tie(nullptr);//���cin��cout�󶨣����⻺���������ʱ(ԭ���󶨣���Ϊ��ȷ����������֮ǰˢ�����������)
    //��By default, the standard input device is tied together with the standard output device in the form: std::cin.tie (&std::cout);
    // which guarantees that the output buffer has been flushed before input is invoked.��
    return 0;
}();
class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0, end = nums.size()-1;
        if(end <= 0) return count;
        int ts = 1, te = min(nums[0],end);
        count = 1;
        if(te == end) return count;
        while(ts <= te){
            count ++;
            int lo = ts, hi = te;
            for(int i = lo; i <= hi; i++){
                if(nums[i]+i > te){
                    te = min(nums[i]+i,end);
                    ts = i + 1;
                    if(te == end) return count;
                }
            }
        }
        return count;
    }
};
int main()
{
    Solution s;
    int a[1000] = {2,3,1,1,4};
    vector<int> vec(a,a+5);
    cout<<s.jump(vec);
    return 0;
}
