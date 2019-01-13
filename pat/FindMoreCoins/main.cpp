#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
/**
    ���ݷ��������Ӳ��������⣨����m��󲻳���100�����ݷ���ȫ�ǿ��еģ�
*/
vector<int> res;
int tb[101];
int n,m,num;
void printVec(vector<int>& vec){
    for(int i = 0; i < vec.size(); i++){
        if(i != 0) cout<<" "<<vec[i];
        else cout<<vec[i];
    }
}
bool find(int m){
    if(m == 0) return true;
    for(int i = 1; i <= m ; i++){
        if(tb[i] > 0){
           tb[i]--;
           if(find(m-i)){
                res.push_back(i);
                return true;
           }else{
               tb[i]++;
           }
        }
    }
    return false;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i < n ;i++){
        scanf("%d",&num);
        if(num <= m){//ֻ��С�ڵ���m��Ӳ�Ҳ��п��ܲ������
           tb[num] += 1;
        }
    }
    if(!find(m)){
        cout<<"No Solution"<<endl;
    }else{
        sort(res.begin(),res.end());//�б�Ҫ����
        printVec(res);
    }
    return 0;
}
