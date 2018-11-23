#include<iostream>
#include<cstdio>
using namespace std;
/**
	通过本题可进一步熟悉插入排序和堆排序，尤其是堆排序的流程：全部下沉建堆（升序就是最大堆，本题语境已经实现此步），然后循环中交换、n减一、下沉调整堆。
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
    //判断是不是插入排序（前面有序，后面乱序部分肯定一一对应）
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
        //再排一步
        int key = aft[j];
        int p = j-1;
        while(p >=0 && aft[p] > key){
            aft[p+1] = aft[p];
            p--;
        }
        aft[p+1] = key;
		//打印
        int k = 0;
        while(k != n-1){
            cout<<aft[k++]<<" ";
        }
        cout<<aft[n-1]<<endl;
    }else{
        cout<<"Heap Sort"<<endl;
        //利用最大堆排升序
        int cur = n-1;
        int key = aft[0];
        while(cur>0 && aft[cur] >= key){
            cur--;
        }
        exch(aft,0,cur);//交换元素
        sink(aft,cur,0);//下沉重建最大堆，cur是为了限定范围
		//打印
        int k = 0;
        while(k != n-1){
            cout<<aft[k++]<<" ";
        }
        cout<<aft[n-1]<<endl;
    }
    return 0;
}
