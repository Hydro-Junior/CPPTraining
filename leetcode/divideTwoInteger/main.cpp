#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool isneg = false;
        LL d = divisor, D = dividend,res = 0;
        if(d < 0 && D < 0) {
            d = -d;
            D = -D;
        }else if(d < 0){
            d = -d;
            isneg = true;
        }else if(D < 0){
            D = -D;
            isneg = true;
        }
        if(D < d) res = 0;
        else if(d == D) res = 1;
        else {
            int p = 0;
            while(d + d < D){
                d = d + d;
                p ++;
            }
            if(d+d == D) {
                res = (LL)pow(2,p+1);
            }else{
                res = (LL)pow(2,p) + divide(D-d,divisor>0?divisor:-divisor);
            }
        }
       if(isneg) res = -res;
       if(res < INT_MIN || res > INT_MAX) return INT_MAX;
       else return res;
    }
};
int main()
{
    Solution s;
    int D = -2147483648,d = -3;
    cout <<s.divide(D,d)<< endl;
    return 0;
}
