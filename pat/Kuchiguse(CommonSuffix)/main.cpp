#include<string>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
/**
    ��Ŀ���ѣ���Ҫ���۵��Ƕ������ݵİ취��
    getline() �����֣�stringͷ�ļ���getline(cin,string)�����Խ��տո�ͻس�(�Ƽ�)��cin.getline(),���Խ��ܿո񣬵����ܽ��ܻس��������β��'\n'
    gets(*char) �Ƽ�������stringͷ�ļ������Խ��ܿո������س����������ʺϰ��ж�ȡ��
    c = getchar() �Ƽ���ͬ������stringͷ�ļ����ʺ϶�ȡ�����������ַ���
    cin.get(char[] , n) �� cin.get()<�޲��������ַ���>
    �����ĸ��˱Ƚ���Ϥ�Ͳ����ܽ��ˣ�������scanf��ȡ�У����޷�ֱ�����string��ʹ�ã����Ƽ�

    �ܵ���˵�����ж�ȡ�ַ������Ƚ���ʹ��getline(cin,string),Ҳ����ʹ�ý���ʹ�� gets(char[]);
*/
int main(){
    /**
        �����ʽ���������ַ�������n���������n���ַ���
    */
    //��һ�֣��Ƽ�
    /*
    int n;
    scanf("%d",&n);
    char ss[n][260];
    getchar();//�����س���
    for(int i = 0 ; i < n; i++){
        gets(ss[i]);
    }
    for(int i = 0 ; i < n; i++){
        cout<<ss[i]<<endl;
    }*/

    //�ڶ���,��fgets��ȡ,�������س���������ʱ���Ƽ�
    /*
    int n ;
    scanf("%d",&n);
    char ss[n][260];
    getchar();
    for(int i = 0 ; i < n; i++){
        fgets(ss[i],sizeof(ss[i]),stdin);//�������ַ�ʽ�������\n!
    }
    for(int i = 0 ; i < n; i++){
        cout<<ss[i]<<endl;
    }*/
    //�����֣�ֱ�Ӷ���string�У��Ƽ�
    int n ;
    /*scanf("%d",&n);
    string ss[n];
    getchar();*/ //���ַ�ʽҲ��
    cin>>n;//����cin���У����и��س���Ҫ�������Ժ������getchar()
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
