#include<sstream>
#include<iostream>
#include<cstdio>
using namespace std;
/**
    �ȽϿ���ϸ�ڴ������������ݱȽ�����(������Ŀ�������൱��ʱ)����Ϊ���в������û�п��ǣ�
    ����00001,0.0֮��Ƚϲ�����������
*/
string count(string& s, int& d){
    string res;//��Ч������
    bool startCount,startAppend;
    bool isSmall = true;
    //�ж��Ƿ�С��1
    int j = 0;
    while(j < s.size()){
        if(s[j] == '0') j++;
        if(s[j] == '.'){//������С���㣬˵���ǽ�С����
            isSmall = true;
            break;
        }
        if(s[j] >'0' && s[j] <='9'){//��С����֮ǰ�������ڵ���1��λ��˵������С����
            isSmall = false;
            break;
        }
    }
    if(isSmall){//��һ�������С��1
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
                    res += s[i];//�����Чֵ
                }
            }
        }
        if(startAppend == false) {//û���κ���Чֵ ����0.0
            d=0;
            res = "0";
        }
    }else{//�ڶ������������1
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
    int d,d1=0,d2=0;//d1,d2��ʾ����Ҫ����10�ļ��η�
    string s1,s2;
    string res1,res2;
    cin>>d>>s1>>s2;
    /*
    ����Ϊ0��ͷ�ľ���С��1�����ˣ�����û�뵽����00001���ֲ���,��ֱ���ں������жϺ���
    if(s1[0]=='0')sm1=true;
    if(s2[0]=='0')sm2=true;*/
    res1 = count(s1,d1);
    res2 = count(s2,d2);
    int len1 = res1.size();
    int len2 = res2.size();
    if(d > len1){//��Чλ����Ļ�Ҫ����
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
