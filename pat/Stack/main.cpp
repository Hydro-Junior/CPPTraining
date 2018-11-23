#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
/**
要求实现一个特殊功能的栈，多一个返回中位数的功能
想了很久，要高效实现，尝试使用两个索引优先队列（c++ stl优先队列并不能提供删除或修改指定元素的功能，自己实现数据结构）
如果索引优先队列写不熟练，本题及其容易出错。
当然还可用树状数组或线段树实现
*/
template<class T>
class IndexPQ{
private:
    int n;
    int* pq;//索引
    int* qp;//索引的索引,为对象找到索引，与对象一一对应,它的下标就是对象的索引
    T* key;//具体对象
    bool isMin; // 是不是最小堆
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
        if(i >= n) return;//超出范围
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
            if(j+1 <= n-1 && better(j+1,j)){j = j+1;}//两个儿子中选个更好的
            if(better(i,j))break;//比两个儿子都好，跳出循环
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
        //cout<<"PQ的析构函数被调用！"<<endl;
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
        qp[i] = n;//此时索引i在队列最末
        n++;//总数增加（注意先增加后上浮），插入删除时最好先调整总数，再上浮或下沉
        swim(n-1);
    }
    void changeKey(int i , T item){
        key[i] = item;
        int idx = qp[i];
        swim(idx);
        sink(idx);
    }
    T pop(){
        int top = pq[0];//得到最大值的索引
        T topVal = key[pq[0]];//得到最大值
        exch(0,n-1);
        n--;//总数减少
        sink(0);
        qp[top] = -1;
        return topVal;
    }
    //返回最值的索引
    int top(){
        return pq[0];
    }
    void remove(int i){
        if(!contains(i)) return;
        int idx = qp[i];//得到索引i的排名
        exch(idx,n-1);//考虑i==n-1的情况
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
    IndexPQ<int> smallHalf;//较小的一半，最大堆
    IndexPQ<int> bigHalf;//较大的一半，最小堆
public:
    Stack(int M):smallHalf(M/2+2, false),bigHalf(M/2+2,true){
        arr = new int[M];
        cap = M;
        n = 0;
    }
    ~Stack(){
        //cout<<"Stack类的析构函数被调用！"<<endl;
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
