#include <iostream>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        if(n == 0) return 1.0;
        bool neg = false;long long N = n;
        if(n < 0) {
            neg = true;
            N = 0 - (long long)n;
        }
        while(N > 0){
            long long k = 1,power = 0;
            while(2 * k <= N){
                k = k * 2;
                power ++;
            }
            double t = x;
            for(int i = 0 ; i < power; i++){
                t *= t;
            }
            res *= t;
            N -= k;
        }
        if(neg) return 1.0/res;
        else return res;
    }
};
/* 递归处理（更简洁，未处理INT_MIN的情况）
public class Solution {
    public double pow(double x, int n) {
        if(n == 0)
            return 1;
        if(n<0){
            n = -n;
            x = 1/x;
        }
        return (n%2 == 0) ? pow(x*x, n/2) : x*pow(x*x, n/2);
    }
}*/
int main()
{
    Solution s;
    cout << s.myPow(0.00001,2147483647) << endl;
    return 0;
}
