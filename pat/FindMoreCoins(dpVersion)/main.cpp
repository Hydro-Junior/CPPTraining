#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
/**
    ��̬�滮��������Ӳ�����⣬Ҳ�ܰ������õ����01��������
*/
vector<int> res[101],coins;
int n,m,num;
void printVec(vector<int>& vec){
    int sz = vec.size();
    for(int i = sz-1; i > 0; i--){//�����ӡ������ӡ0
        if(i != sz-1) cout<<" "<<vec[i];
        else cout<<vec[i];
    }
    cout<<endl;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i < n ;i++){
        scanf("%d",&num);
        if(num <= m){
           coins.push_back(num);
        }
    }
    int sz = coins.size();
    sort(coins.begin(),coins.end());
    res[0].push_back(0);
    for(int i = sz - 1 ; i >= 0; i--){//(Խ��Ӳ��Խ�ã����϶��ǽ�СӲ�ҵķ���)
        //cout<<"coins["<<i<<"]= "<<coins[i]<<endl;
        for(int j = m; j >= coins[i]; j--){//Ӳ��ֻ��1�����Ӵ�С���£���0-1�����Ӹߵ���׹�䣬���ظ��ۻ������ر����ӵ͵��ߣ��ظ����ۣ�
            if(res[j-coins[i]].size()) {
                res[j]=res[j-coins[i]];//����������ֵ
                res[j].push_back(coins[i]);
            }
        }
        //��ӡ����ֵ
        /*for(int i = 0 ; i <= m ; i++){
            cout<<i<<": ";
            printVec(res[i]);
        }
        cout<<"------------------------------------"<<endl;*/
    }
    if(res[m].size()==0){
        cout<<"No Solution"<<endl;
    }else{
        printVec(res[m]);
    }
    return 0;
}

