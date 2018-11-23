#include<iostream>
#include<cstdio>
using namespace std;
/**
	ͨ������ɽ�һ����Ϥ��������Ͷ����������Ƕ���������̣�ȫ���³����ѣ�����������ѣ������ﾳ�Ѿ�ʵ�ִ˲�����Ȼ��ѭ���н�����n��һ���³������ѡ�
*/
void sink(int d[], int len , int i){
    void exch(int d[], int i , int j);
    while(2*i+1 < len){
        int j = 2*i+1;
        if(j+1 < len && d[j+1] > d[j]) j=j+1;
        if(d[j] > d[i]) exch(d,i,j);
        else break;
        i = j;
    }
}
void exch(int d[], int i , int j){
    int tmp = d[i];
    d[i] = d[j];
    d[j] = tmp;
}
int main(){
    int n;
    scanf("%d",&n);
    int pre[n];
    int aft[n];
    for(int i = 0 ; i < n; i++){
        scanf("%d",&pre[i]);
    }
    for(int i = 0 ; i < n; i++){
        scanf("%d",&aft[i]);
    }
    //�ж��ǲ��ǲ�������ǰ�����򣬺������򲿷ֿ϶�һһ��Ӧ��
    int j = 1;
    while(aft[j] >= aft[j-1]){
        j++;
    }
    bool isIns = true;
    for(int i = j; i < n ; ){
        if(aft[i] == pre[i]) i++;
        else {
            isIns = false;
            break;
        }
    }
    if(isIns){
        cout<<"Insertion Sort"<<endl;
        //����һ��
        int key = aft[j];
        int p = j-1;
        while(p >=0 && aft[p] > key){
            aft[p+1] = aft[p];
            p--;
        }
        aft[p+1] = key;
		//��ӡ
        int k = 0;
        while(k != n-1){
            cout<<aft[k++]<<" ";
        }
        cout<<aft[n-1]<<endl;
    }else{
        cout<<"Heap Sort"<<endl;
        //��������������
        int cur = n-1;
        int key = aft[0];
        while(cur>0 && aft[cur] >= key){
            cur--;
        }
        exch(aft,0,cur);//����Ԫ��
        sink(aft,cur,0);//�³��ؽ����ѣ�cur��Ϊ���޶���Χ
		//��ӡ
        int k = 0;
        while(k != n-1){
            cout<<aft[k++]<<" ";
        }
        cout<<aft[n-1]<<endl;
    }
    return 0;
}
