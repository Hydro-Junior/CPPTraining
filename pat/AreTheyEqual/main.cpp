#include<sstream>
#include<iostream>
#include<cstdio>
using namespace std;
/**
    比较考验细节处理能力的数据比较问题(这类题目初次做相当费时)，因为总有不少情况没有考虑，
    比如00001,0.0之类比较不正常的输入
*/
string count(string& s, int& d){
    string res;//有效的数字
    bool startCount,startAppend;
    bool isSmall = true;
    //判断是否小于1
    int j = 0;
    while(j < s.size()){
        if(s[j] == '0') j++;
        if(s[j] == '.'){//先遇到小数点，说明是较小的数
            isSmall = true;
            break;
        }
        if(s[j] >'0' && s[j] <='9'){//在小数点之前遇到大于等于1的位，说明不是小的数
            isSmall = false;
            break;
        }
    }
    if(isSmall){//第一种情况，小于1
        startCount = false; startAppend=false;
        for(int i = j ; i < s.size(); i++){
            if(s[i]=='.'){
                startCount = true;
                continue;
            }else{
                if(startCount && s[i] == '0'){
                    d--;
                }else if(startCount && s[i] != '0'){
                    startCount = false;
                    startAppend = true;
                    res += s[i];
                }else if(!startCount && startAppend){
                    res += s[i];//添加有效值
                }
            }
        }
        if(startAppend == false) {//没有任何有效值 比如0.0
            d=0;
            res = "0";
        }
    }else{//第二种情况，大于1
        startCount = true;
        for(int i = j; i < s.size(); i++){
            if(s[i]=='.'){
                startCount = false;
                continue;
            }else{
                if(startCount) d++;
                res += s[i];
            }
        }
    }
    return res;
}
int main(){
    int d,d1=0,d2=0;//d1,d2表示最终要乘以10的几次方
    string s1,s2;
    string res1,res2;
    cin>>d>>s1>>s2;
    /*
    本以为0开头的就是小于1的数了，可是没想到还有00001这种操作,就直接在函数里判断好了
    if(s1[0]=='0')sm1=true;
    if(s2[0]=='0')sm2=true;*/
    res1 = count(s1,d1);
    res2 = count(s2,d2);
    int len1 = res1.size();
    int len2 = res2.size();
    if(d > len1){//有效位数多的话要补零
        for(int i = 0 ; i < d-len1; i++){
            res1 += '0';
        }
    }
    if(d > len2){
        for(int i = 0; i< d-len2; i++){
            res2 += '0';
        }
    }
    res1 = res1.substr(0,d);
    res2 = res2.substr(0,d);
    if(d1==d2 && res1==res2){
        cout<<"YES "<<"0."<<res1<<"*10^"<<d1;
    }else{
        cout<<"NO ";
        cout<<"0."<<res1<<"*10^"<<d1<<" ";
        cout<<"0."<<res2<<"*10^"<<d2;
    }
    return 0;
}
