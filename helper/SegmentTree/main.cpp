#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
/**
    线段树，准确地来说是IndexedSegmentTree，因为要知道具体是哪一个值最大或最小，引入模板后适用范围更广(常用于RMQ,即区间最值查询，更新和查询方便，空间复杂度O(n),时间复杂度O(logn))
*/
template<class T>
class SegmentTree{
private:
    T *data;
    int data_size;
    int n; //线段树最后一层的规模大小
    bool isMin; //RMQ查询最小值还是最大值

    int better(int i, int j){//返回下标
        if(i == -1) return j;
        if(j == -1) return i;
        if(isMin) return data[i] < data[j] ? i : j;
        else return data[i] < data[j] ? j : i;
    }

    int mid(int s, int e){return s + (e-s)/2;}

    int query(int qs, int qe, int ss, int se, int k){//查询区间（递归过程中不变）【qs,qe】; 节点区间【ss,se】, 与节点下标k对应，比如下标0和区间 【0,data_size-1】对应
        if(qs > se || qe < ss ) return -1;//没有交集
        if(qs <= ss && qe >= se) return st[k]; //查询区间包含当前节点的区间
        int m = mid(ss,se);
        return better(query(qs, qe, ss, m, 2*k+1),query(qs, qe, m+1, se, 2*k+2));
    }

public:
    int *st;//线段树，存储下标
    SegmentTree(T _data[],int _n,bool _isMin):data(_data),data_size(_n),isMin(_isMin){
        n = 1;
        while(n < data_size){
            n *= 2;
        }
        st = new int[2 * n - 1];
        fill(st, st + 2 * n - 1, -1);
        for(int i = 0 ; i < data_size; i++){
            update(i,data[i]);
        }
    }
    ~SegmentTree(){
        delete []st;
    }
    void update(int k, T val){
        data[k] = val;
        k += n - 1; //定位到最后一层
        st[k] = k - n + 1;
        while(k > 0){
            k = (k-1)/2;
            st[k] = better(st[2*k+1], st[2*k+2]);
        }
    }
    //提供给外部的查询接口，输入数据查询范围即可
    int query(int qs, int qe){
        return query(qs, qe, 0, data_size-1, 0);
    }
};

//测试线段树
int main()
{
    double arr[21]{1.2, 4.3, 0.9, 1.4, 5.6, 39.8, 7.3, 8.6, 9.4, -2.4,
                -0.5, -13.5, 7, 6.54, 3.14, 2.33 , 4.5, 33.2, 9.0, 5.8, 6.9};
    SegmentTree<double> stMin(arr, 21, true);
    SegmentTree<double> stMax(arr, 21, false);

    cout<<stMin.query(1,20)<<endl;
    cout<<stMax.query(1,20)<<endl;

    cout<<"更新前"<<endl;
    for(int i = 0 ; i < 32*2-1 ; i++){
        cout<<stMin.st[i]<<" ";
    }
    cout<<endl<<endl;

    stMax.update(3,100);
    cout<<"将data[3]更新为100后："<<endl;
    for(int i = 0 ; i < 32*2-1 ; i++){
        cout<<stMax.st[i]<<" ";
    }
    cout<<endl<<endl;

    stMin.update(4,-100);
    cout<<"将data[14]更新为-100后："<<endl;
    for(int i = 0 ; i < 32*2-1 ; i++){
        cout<<stMin.st[i]<<" ";
    }
    cout<<endl<<endl;


    cout<<stMin.query(1,20)<<endl;
    cout<<stMin.query(10,13)<<endl;
    cout<<stMin.query(2,3)<<endl;
    cout<<stMin.query(14,17)<<endl;

    cout<<stMax.query(1,20)<<endl;
    cout<<stMax.query(10,13)<<endl;
    cout<<stMax.query(2,3)<<endl;
    cout<<stMax.query(14,17)<<endl;
    return 0;
}
