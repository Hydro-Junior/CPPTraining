#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
/**
    ���⺬��ͦ�ߣ�����AVL���Ĳ���ʵ�֣��ؼ�����ƽ�ⷽ���͸߶ȸ��¡�
    �ر�ע�����û�з���ֵ�Ĳ��뺯��ָ���β�Ҫ�����ã���Ȼ�������Ǹ�������ʵ�ʵ�root�������Ӱ�죡
*/
const int ALLOWED_IMBALANCE = 1;//�������߶Ȳ�Ϊ1
class Node{
public:
    int val;
    int h;
    Node* left;
    Node* right;
    Node(int v):val(v),h(0),left(NULL),right(NULL){}
    ~Node(){delete left; delete right;}
};
class AVL{
public:
    Node* root;
    AVL(){
        root = NULL;
    }
    ~AVL(){delete root;}
    void insert(int v){
       insert(v, root);
    }
private:
    void insert(int v, Node* &nd){//�β���ָ������ã�
        if(!nd) nd = new Node(v);
        else if(v < nd->val){
            insert(v, nd->left);
        }else if(v > nd->val){
            insert(v,nd->right);
        }
        nd = balance(nd);
    }
    //�ұ߽ڵ�����
    Node* rotate2Left(Node* nd){//���ܺ�������ָ���������ֵ����ζ�Ż������¸�ֵ�Ĳ�����������Ҫ������
        Node* node = nd->right;
        nd->right = node->left;
        node->left = nd;
         //�����߶�
        nd->h = max(hof(nd->right),hof(nd->left))+1;
        node->h = max(hof(node->left),hof(node->right))+1;
        return node;
    }
    //��߽ڵ�����
    Node* rotate2Right(Node* nd){
        Node* node = nd->left;
        nd->left = node->right;
        node->right = nd;
        //�����߶�
        nd->h = max(hof(nd->right),hof(nd->left))+1;
        node->h = max(hof(node->left),hof(node->right))+1;
        return node;
    }
    //���ұ߽ڵ��˫��ת
    Node* double2Left(Node* nd){
        nd->right = rotate2Right(nd->right);
        return rotate2Left(nd);
    }
    //����߽ڵ��˫��ת
    Node* double2Right(Node* nd){
        nd->left = rotate2Left(nd->left);
        return rotate2Right(nd);
    }
    Node* balance(Node* t){//���û�з���ֵ�Ĳ���������ͨ����Ҫ���˼����ã�
        if(t == NULL) return t;
        if(hof(t->left) - hof(t->right) > ALLOWED_IMBALANCE){//��߸�
            if(hof(t->left->left) >= hof(t->left->right)){//������
                t = rotate2Right(t);
            }else{t = double2Right(t);}//������
        }else if(hof(t->right) - hof(t->left) > ALLOWED_IMBALANCE){//�ұ߸�
            if(hof(t->right->right) >= hof(t->right->left)){//������
                t = rotate2Left(t);
            }else{t = double2Left(t);}//������
        }
        t->h = max(hof(t->left),hof(t->right))+1;//�����߶�
        return t;
    }
    int hof(Node* node){
        return node==NULL?-1:node->h;
    }
};
int n,num;
int main(){
    AVL AvlTree;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&num);
        AvlTree.insert(num);
    }
    cout<<(AvlTree.root)->val;
    return 0;
}
