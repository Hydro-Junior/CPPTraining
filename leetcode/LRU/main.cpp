#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
/**
    LRU����ģ�ͣ������ǹ�ϣ����˫������
    ����list���Լ�ʵ���ˣ�Ҳ����ʹ��stl��list����������ࣨ�ο�ע�Ͳ��ֵĴ��룩
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
    Node* first;//����ͷ
    Node* last;//����β������涨���ʹ�õķ��ڶ���β
    unordered_map<int,Node*> mp;
public:
    LRUCache(int capacity):cap(capacity),size(0),first(new Node(-1,-1)),last(first),mp(){}//һ��ʼ����β�Ͷ���ͷ�غ�
    int get(int key) {
        if(!mp.count(key)) return -1;
        else{
           Node* node =  mp[key];
           if(node == last) return node->val;//����ڵ��Ѿ��ڶ�β
           //�ѽڵ���м�ɾ��
           if(node->next) node->next->pre = node->pre;
           node->pre->next = node->next;
           //�ѽڵ�嵽���
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
        if(mp.count(key)){//����Ѿ����ڣ��Ƴ���
            maptr it =  mp.find(key);
            Node* nd = it->second;
            if(nd->next) nd->next->pre = nd->pre;
            nd->pre->next = nd->next;
            mp.erase(it);
        }else if(size == cap){//���û����ͬkey������������
            if(cap == 0) return;
            int rmk = first->next->key;
            maptr it =  mp.find(rmk);
            mp.erase(it);
            Node* head = first->next->next;
            if(head) head->pre = first;
            first->next = head;
        }else{//����δ�������ظ�key
            size++;
        }
        mp[key] = node;
    }
};
/**
//�������ύ�����ʴ𰸣�ֵ�òο�
class LRUCache {
    int capacity;
    list<pair<int, int>> li;
    unordered_map<int, list<pair<int, int>>::iterator> um; //valueֵ�ŵ�����������

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (um.find(key) == um.end()) return -1;
        li.splice(li.begin(), li, um[key]);//ѡ����Ԫ�ز嵽��ͷ
        return um[key]->second;
    }

    void put(int key, int value) {
        if (get(key) != -1) {//ע�������Ѿ��Զ��н����˵���
            //�Ѿ����ڴ�key�����
            um[key]->second = value;
            return;
        }

        if (um.size() == capacity) {//�Ѿ��ﵽ�������ƣ�ɾ����βLRU��Ԫ��
            int delKey = li.back().first;
            li.pop_back();
            um.erase(delKey);
        }
        //������Ԫ�أ�����emplace_frontֱ�ӵ���Ԫ�صĹ��캯��ʵ�ֲ��룬��push_front(pair(key,value))���
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
