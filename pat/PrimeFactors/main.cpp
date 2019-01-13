#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
using namespace std;
/**
    �ֽ�һ����97532468=2^2*11*17*101*1291
    ����ɸ���map
*/
int main(){
    int num;
    scanf("%d",&num);
    cout<<num<<"=";
    int lim = (int)ceil(sqrt(num));//����������ֵ����
    bool isPrime[lim+1];
    fill(isPrime,isPrime+lim+1,true);//һ��ʼȫ������
    map<int,int> resmap;
    for(int i = 2; i <= lim; i++){
        if(isPrime[i]){
            for(int j = 2 ; j * i <= lim; j++){
                isPrime[j*i] = false;//��Ǻ���
            }
            int k = 0;
            while(num != 0 && num % i == 0){
                k++;
                num /= i;
            }
            if(k > 0) resmap.insert({i,k});
        }
        if(num <= 1) break;
    }

    for(map<int,int>::iterator it = resmap.begin(); it != resmap.end(); it++){
            if(it != resmap.begin()){
                cout<<"*";
            }
            if(it->second == 1)cout<<it->first;
            else cout<<it->first<<"^"<<it->second;
    }
    if(resmap.empty())cout<<num;
    else if(num > 1)cout<<"*"<<num;
    return 0;
}
