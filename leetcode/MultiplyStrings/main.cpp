#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        int a[n1+n2];//两树相乘，位数不超过n1+n2
        memset(a,0,sizeof(a));
        string res;
        int p,q,mul,rest,dig,pos;
        for(int i = 0 ; i < n1; i++){
            for(int j = 0; j < n2; j++){
                pos = i+j+1;//结果低位所在位置，高位就是pos+1
                p = num1[i]-'0';
                q = num2[j]-'0';
                mul = p*q;
                dig = mul % 10;
                rest = mul/10;
                a[pos] += dig;
                a[pos-1] += rest;
            }
        }
        //调整并构建结果
        rest = 0;
        for(int i = n1+n2-1; i >= 0; i--){
            a[i] += rest; rest=0;
            if(a[i] >= 10){
                rest = a[i]/10;
                a[i] %= 10;
            }
        }
        int k = 0;
        while(k < n1+n2 && a[k]==0){  k++;}
        if(k == n1+n2){return res = "0";}
        for(int i = k; i < n1+n2; i++){
            char c = a[i]+'0';
            res += c;
        }
        return res;
    }
};
int main()
{
    Solution s;
    string s1 = "123";
    string s2 = "456";
    cout << s.multiply(s1,s2)<< endl;
    return 0;
}
