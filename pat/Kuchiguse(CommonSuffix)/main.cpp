#include<string>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
/**
    题目不难，需要讨论的是读入数据的办法：
    getline() 有两种：string头文件的getline(cin,string)，可以接收空格和回车(推荐)；cin.getline(),可以接受空格，但不能接受回车，数组结尾是'\n'
    gets(*char) 推荐，属于string头文件，可以接受空格，遇到回车结束，很适合按行读取。
    c = getchar() 推荐，同样属于string头文件，适合读取或跳过单个字符。
    cin.get(char[] , n) 或 cin.get()<无参数，跳字符用>
    其他的个人比较熟悉就不做总结了，可以用scanf读取行，但无法直接配合string类使用，不推荐

    总的来说，按行读取字符串首先建议使用getline(cin,string),也可以使用建议使用 gets(char[]);
*/
int main(){
    /**
        输入格式：先输入字符串行数n，随后输入n行字符串
    */
    //第一种，推荐
    /*
    int n;
    scanf("%d",&n);
    char ss[n][260];
    getchar();//跳过回车符
    for(int i = 0 ; i < n; i++){
        gets(ss[i]);
    }
    for(int i = 0 ; i < n; i++){
        cout<<ss[i]<<endl;
    }*/

    //第二种,用fgets读取,但会读入回车符，做题时不推荐
    /*
    int n ;
    scanf("%d",&n);
    char ss[n][260];
    getchar();
    for(int i = 0 ; i < n; i++){
        fgets(ss[i],sizeof(ss[i]),stdin);//但用这种方式将会读入\n!
    }
    for(int i = 0 ; i < n; i++){
        cout<<ss[i]<<endl;
    }*/
    //第三种，直接读到string中，推荐
    int n ;
    /*scanf("%d",&n);
    string ss[n];
    getchar();*/ //这种方式也行
    cin>>n;//光用cin不行，还有个回车需要处理，所以后面跟个getchar()
    getchar();
    string ss[n];
    for(int i = 0 ; i < n; i++){
        getline(cin,ss[i]);
        reverse(ss[i].begin(),ss[i].end());
    }
    int len = ss[0].size();
    for(int i = 1 ; i < n; i++){
        int tmpLen = 0;
        for(int j = 0; j < len && j < ss[i].size(); j++){
            if(ss[i][j] == ss[0][j]) tmpLen++;
            else break;
        }
        len = min(len,tmpLen);
    }
    if(len == 0) cout<<"nai";
    else{
        for(int i = 0 ; i < len; i++){
            cout<<ss[0][len-i-1];
        }
    }
    return 0;
}
