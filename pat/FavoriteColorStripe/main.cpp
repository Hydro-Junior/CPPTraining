#include<iostream>
using namespace std;
int N,M,L,tp,sq[201],pos[201],dp[201],colors[10001];
int main(){
    cin>>N>>M;
    for(int i = 1 ; i <= M ; i++){
        cin >> tp;
        pos[tp] = i;//��ɫtp��ϲ���������е�λ��
        sq[i] = tp;//ϲ���ĵ�i����ɫ��tp
    }
    cin >> L;
    for(int i = 1; i <= L; i++){
        cin>>colors[i];
    }
    for(int i = 1; i <= L; i++){
        int c = colors[i];
        if(pos[c] != 0){//������ɫ��ϲ����������
            int subMax = 0;
            for(int j = 1; j <= pos[c]; j++){
                subMax = max(subMax,dp[sq[j]]);//�ҵ�ǰ��������
            }
            dp[c] = subMax + 1;//dp�����ʾ���±�c��β������еĳ���
        }
    }
    int res = 0;
    for(int i = 1 ;i <= N ;i ++){
        res = max(dp[i],res);//�Ƚϵó����ĳ���
    }
    cout<<res;
    return 0;
}
