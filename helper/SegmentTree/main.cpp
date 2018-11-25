#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
/**
    �߶�����׼ȷ����˵��IndexedSegmentTree����ΪҪ֪����������һ��ֵ������С������ģ������÷�Χ����(������RMQ,��������ֵ��ѯ�����ºͲ�ѯ���㣬�ռ临�Ӷ�O(n),ʱ�临�Ӷ�O(logn))
*/
template<class T>
class SegmentTree{
private:
    T *data;
    int data_size;
    int n; //�߶������һ��Ĺ�ģ��С
    bool isMin; //RMQ��ѯ��Сֵ�������ֵ

    int better(int i, int j){//�����±�
        if(i == -1) return j;
        if(j == -1) return i;
        if(isMin) return data[i] < data[j] ? i : j;
        else return data[i] < data[j] ? j : i;
    }

    int mid(int s, int e){return s + (e-s)/2;}

    int query(int qs, int qe, int ss, int se, int k){//��ѯ���䣨�ݹ�����в��䣩��qs,qe��; �ڵ����䡾ss,se��, ��ڵ��±�k��Ӧ�������±�0������ ��0,data_size-1����Ӧ
        if(qs > se || qe < ss ) return -1;//û�н���
        if(qs <= ss && qe >= se) return st[k]; //��ѯ���������ǰ�ڵ������
        int m = mid(ss,se);
        return better(query(qs, qe, ss, m, 2*k+1),query(qs, qe, m+1, se, 2*k+2));
    }

public:
    int *st;//�߶������洢�±�
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
        k += n - 1; //��λ�����һ��
        st[k] = k - n + 1;
        while(k > 0){
            k = (k-1)/2;
            st[k] = better(st[2*k+1], st[2*k+2]);
        }
    }
    //�ṩ���ⲿ�Ĳ�ѯ�ӿڣ��������ݲ�ѯ��Χ����
    int query(int qs, int qe){
        return query(qs, qe, 0, data_size-1, 0);
    }
};

//�����߶���
int main()
{
    double arr[21]{1.2, 4.3, 0.9, 1.4, 5.6, 39.8, 7.3, 8.6, 9.4, -2.4,
                -0.5, -13.5, 7, 6.54, 3.14, 2.33 , 4.5, 33.2, 9.0, 5.8, 6.9};
    SegmentTree<double> stMin(arr, 21, true);
    SegmentTree<double> stMax(arr, 21, false);

    cout<<stMin.query(1,20)<<endl;
    cout<<stMax.query(1,20)<<endl;

    cout<<"����ǰ"<<endl;
    for(int i = 0 ; i < 32*2-1 ; i++){
        cout<<stMin.st[i]<<" ";
    }
    cout<<endl<<endl;

    stMax.update(3,100);
    cout<<"��data[3]����Ϊ100��"<<endl;
    for(int i = 0 ; i < 32*2-1 ; i++){
        cout<<stMax.st[i]<<" ";
    }
    cout<<endl<<endl;

    stMin.update(4,-100);
    cout<<"��data[14]����Ϊ-100��"<<endl;
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
