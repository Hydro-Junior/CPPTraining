#include<iostream>
#include<cstdio>
#include<sstream>
using namespace std;
/**
    本题还是熟悉c++数据读取，java用nextInt()很简单
    整数用.分隔，本来用下面的方法先读字符串再拆分，但也可以这样: scanf("%d.%d.%d",&a1,&a2,&a3)
*/
int main(){
    long a[3]={};
    long b[3]={};
    long c1,c2,c3;
    string s1,s2;
    cin>>s1>>s2;
    //cout<<"收到字符串:"<<s1<<" "<<s2;
    stringstream ss1(s1),ss2(s2);
    char c;
    int i = 0;
    while(ss1>>c){
        if(c !='.'){
           a[i] = a[i]*10 + c-'0';
        }else{
            i++;
        }
    }
    i = 0;
    while(ss2>>c){
        if(c !='.'){
           b[i] = b[i]*10 + c -'0';
        }else{
            i++;
        }
    }
    /*cout<<"读到数据:"<<endl;
    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
    cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<endl;*/
    int add1 = 0, add2 = 0;
    c3 = (a[2] + b[2])%29;
    add2 = (a[2]  + b[2])/29;
    c2 = (a[1] + b[1] + add2)%17;
    add1 = (a[1] + b[1] + add2)/17;
    c1 = a[0] + b[0] + add1;
    cout<<c1<<"."<<c2<<"."<<c3;
    return 0;
}
