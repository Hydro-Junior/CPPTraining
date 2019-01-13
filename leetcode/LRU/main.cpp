#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
/**
    LRU缓存模型，核心是哈希表结合双向链表
    这里list就自己实现了，也可以使用stl的list，代码会更简洁（参考注释部分的代码）
*/
static int n = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Node{
public:
    int key;
    int val;
    Node* pre;
    Node* next;
    Node(int k,int v):key(k),val(v),pre(NULL),next(NULL){}
};
typedef unordered_map<int,Node*>::iterator maptr;
class LRUCache {
private:
    int cap;
    int size;
    Node* first;//队列头
    Node* last;//队列尾，这里规定最近使用的放在队列尾
    unordered_map<int,Node*> mp;
public:
    LRUCache(int capacity):cap(capacity),size(0),first(new Node(-1,-1)),last(first),mp(){}//一开始队列尾和队列头重合
    int get(int key) {
        if(!mp.count(key)) return -1;
        else{
           Node* node =  mp[key];
           if(node == last) return node->val;//如果节点已经在队尾
           //把节点从中间删除
           if(node->next) node->next->pre = node->pre;
           node->pre->next = node->next;
           //把节点插到最后
           node->pre = last;
           last->next = node;
           node->next = NULL;
           last = node;
           return node->val;
        }
    }

    void put(int key, int value) {
        Node* node = new Node(key,value);
        if(last == first){
            first->next = node;
            node->pre = first;
        }else{
            last->next = node;
            node->pre = last;
        }
        last = node;
        last->next = NULL;
        if(mp.count(key)){//如果已经存在，移除它
            maptr it =  mp.find(key);
            Node* nd = it->second;
            if(nd->next) nd->next->pre = nd->pre;
            nd->pre->next = nd->next;
            mp.erase(it);
        }else if(size == cap){//如果没有相同key，且容量到了
            if(cap == 0) return;
            int rmk = first->next->key;
            maptr it =  mp.find(rmk);
            mp.erase(it);
            Node* head = first->next->next;
            if(head) head->pre = first;
            first->next = head;
        }else{//容量未到且无重复key
            size++;
        }
        mp[key] = node;
    }
};
/**
//其他人提交的优质答案，值得参考
class LRUCache {
    int capacity;
    list<pair<int, int>> li;
    unordered_map<int, list<pair<int, int>>::iterator> um; //value值放迭代器，很妙

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (um.find(key) == um.end()) return -1;
        li.splice(li.begin(), li, um[key]);//选出该元素插到队头
        return um[key]->second;
    }

    void put(int key, int value) {
        if (get(key) != -1) {//注意这里已经对队列进行了调整
            //已经存在此key的情况
            um[key]->second = value;
            return;
        }

        if (um.size() == capacity) {//已经达到容量限制，删除队尾LRU的元素
            int delKey = li.back().first;
            li.pop_back();
            um.erase(delKey);
        }
        //插入新元素，这里emplace_front直接调用元素的构造函数实现插入，和push_front(pair(key,value))差不多
        li.emplace_front(key, value);
        um[key] = li.begin();
    }
};
*/
int main()
{
    LRUCache lru(1);
    lru.put(2,1);
    cout<<lru.get(2)<<endl;
    lru.put(3,2);
    cout<<lru.get(2)<<endl;
    cout<<lru.get(3)<<endl;
    return 0;
}
