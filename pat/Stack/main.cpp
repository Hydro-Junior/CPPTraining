#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
/**
Ҫ��ʵ��һ�����⹦�ܵ�ջ����һ��������λ���Ĺ���
���˺ܾã�Ҫ��Чʵ�֣�����ʹ�������������ȶ��У�c++ stl���ȶ��в������ṩɾ�����޸�ָ��Ԫ�صĹ��ܣ��Լ�ʵ�����ݽṹ��
����������ȶ���д�����������⼰�����׳���
��Ȼ��������״������߶���ʵ��
*/
template<class T>
class IndexPQ{
private:
    int n;
    int* pq;//����
    int* qp;//����������,Ϊ�����ҵ������������һһ��Ӧ,�����±���Ƕ��������
    T* key;//�������
    bool isMin; // �ǲ�����С��
    int capacity;
    void exch(int i, int j){
        int tmp = pq[i];
        pq[i] = pq[j];
        pq[j] = tmp;
        qp[pq[i]] = i;
        qp[pq[j]] = j;
    }
    bool better(int i , int j){
        if(isMin) return key[pq[i]] < key[pq[j]];
        else return key[pq[i]] > key[pq[j]];
    }
    void swim(int i){
        if(i >= n) return;//������Χ
        int k = i;
        while(k > 0){
            int j = (k-1)/2;
            if(better(j,k)) break;
            exch(j,k);
            k = j;
        }
    }
    void sink(int i){
        if(i >= n) return;
        while(i*2+1 <= n-1){
            int j = i*2+1;
            if(j+1 <= n-1 && better(j+1,j)){j = j+1;}//����������ѡ�����õ�
            if(better(i,j))break;//���������Ӷ��ã�����ѭ��
            exch(i,j);
            i = j;
        }
    }
public:
    IndexPQ(int M,bool isMinPQ){
        n = 0;
        pq =new int[M];
        qp =new int[M];
        key = new T[M];
        isMin = isMinPQ;
        capacity = M;
        for(int i = 0 ; i < M ;i++){
            qp[i] = -1;
        }
    }
    ~IndexPQ(){
        //cout<<"PQ���������������ã�"<<endl;
        delete []pq;
        delete  []qp;
        delete []key;
    }
    void insert(int i, T item){
        if(contains(i)) {
            changeKey(i,item);
            return;
        }
        key[i] = item;
        pq[n] = i;
        qp[i] = n;//��ʱ����i�ڶ�����ĩ
        n++;//�������ӣ�ע�������Ӻ��ϸ���������ɾ��ʱ����ȵ������������ϸ����³�
        swim(n-1);
    }
    void changeKey(int i , T item){
        key[i] = item;
        int idx = qp[i];
        swim(idx);
        sink(idx);
    }
    T pop(){
        int top = pq[0];//�õ����ֵ������
        T topVal = key[pq[0]];//�õ����ֵ
        exch(0,n-1);
        n--;//��������
        sink(0);
        qp[top] = -1;
        return topVal;
    }
    //������ֵ������
    int top(){
        return pq[0];
    }
    void remove(int i){
        if(!contains(i)) return;
        int idx = qp[i];//�õ�����i������
        exch(idx,n-1);//����i==n-1�����
        n--;
        swim(idx);
        sink(idx);
        qp[i] = -1;
    }
    int size(){return n;}
    bool contains(int i){
        return qp[i] != -1;
    }
    bool isEmpty(){
        return n == 0;
    }
};
class Stack{
private:
    int* arr;
    int n;
    int cap;
    IndexPQ<int> smallHalf;//��С��һ�룬����
    IndexPQ<int> bigHalf;//�ϴ��һ�룬��С��
public:
    Stack(int M):smallHalf(M/2+2, false),bigHalf(M/2+2,true){
        arr = new int[M];
        cap = M;
        n = 0;
    }
    ~Stack(){
        //cout<<"Stack����������������ã�"<<endl;
        delete []arr;
    }
    void push(int item){
        arr[n] = item;
        if(smallHalf.isEmpty() || item <= arr[smallHalf.top()]){
            smallHalf.insert(n,item);
        }else{
            bigHalf.insert(n,item);
        }
        balanceHeaps();
        n++;
    }
    void pop(){
        if(n == 0){
          cout<<"Invalid"<<endl;
          return;
        }
        cout<<arr[--n]<<endl;
        smallHalf.remove(n);
        bigHalf.remove(n);
        balanceHeaps();
    }
    void balanceHeaps(){
        if(smallHalf.size() > bigHalf.size()+1){
            int idx = smallHalf.top();
            bigHalf.insert(idx,smallHalf.pop());
        }else if(bigHalf.size() > smallHalf.size()){
            int idx = bigHalf.top();
            smallHalf.insert(idx,bigHalf.pop());
        }
    }
    void median(){
        if(n==0){
          cout<<"Invalid"<<endl;
          return;
        }
        cout<<arr[smallHalf.top()]<<endl;
    }
};
char s[12];
int main(){
    int n;
    scanf("%d",&n);
    Stack stack = Stack(n);
    for(int i=0 ; i<n; i++){
        int d ;
        scanf("%s",s);
        if(strcmp(s,"Push")==0){
            scanf("%d",&d);
            stack.push(d);
        }else if(strcmp(s,"Pop")==0){
            stack.pop();
        }else{
            stack.median();
        }
    }
    return 0;
}
