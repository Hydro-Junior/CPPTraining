#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
    经典问题：两个有序数组，找出中位数
    这里尝试findKth方法（找两个数组中第k大的数，适用性更广），而非二分查找（已在leetcode中用过“填位切割方式”）
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int sizesum = a.size() + b.size();
        int k = (sizesum + 1)/2;
        double lt,ri;
        lt = ri = findKth(a, b ,k);
        if(sizesum % 2 == 0){
            ri = findKth(a,b,k+1);
        }
        return (lt + ri)/2;
    }
     int findKth(vector<int> &a, vector<int> &b,int k){
        return theKth(a,0,a.size()-1,b,0,b.size()-1,k);
     }
private:
    int theKth(vector<int> &a, int as, int ae, vector<int> &b, int bs, int be, int k){
        if(as > ae) return b[bs + k - 1];
        if(bs > be) return a[as + k - 1];
        int am = (as + ae)/2;
        int bm = (bs + be)/2;
        if(a[am] <= b[bm]){//确定了a[0]-a[am]在总数组的左半部，b[bm]-b[bs]在右半部，其他不确定
            if(k <= am - as + bm - bs + 1) return theKth(a, as, ae, b, bs, bm-1, k);//如果k在左半部，可以排除b的右半部分
            else return theKth(a, am+1, ae, b, bs, be, k-(am-as+1));//如果k在右半部，可以排除a的左半部分，同时调整k
        }else{//与上个分支相反
            if(k <= am - as + bm - bs + 1) return theKth(a, as, am - 1, b, bs, be, k);
            else return theKth(a, as, ae, b, bm + 1, be, k-(bm-bs+1));
        }
    }
    //better Solution for Kth(参考一下，难理解一些 vector转数组用 memcpy(int[],&vector[0],vector.size()*sizeof(int)))
    int kth(int a[],int m, int b[],int n, int k){
        if(m < n) return kth(b,n,a,m,k);
        if(n == 0) return a[k-1];
        if(k == 1) return min(a[0],b[0]);

        int j = min(n, k/2);//b[n]是较小的那组
        int i = k - j;
        if(a[i-1] > b[j-1]) return kth(a, i, b+j, n-j,k-j);
        return kth(a+i,m-i,b,j,k-i);
    }

};


int main()
{
    Solution s;
    int a[] = {1,2};
    int b[] = {3,4};
    vector<int> v1(a,a+2), v2(b,b+2);
    cout << s.findMedianSortedArrays(v1,v2) << endl;
    cout << s.findKth(v1,v2,3)<<endl;
    return 0;
}
