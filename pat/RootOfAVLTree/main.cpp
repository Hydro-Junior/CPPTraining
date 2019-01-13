#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
/**
    此题含量挺高，考察AVL树的插入实现，关键在于平衡方法和高度更新。
    特别注意对于没有返回值的插入函数指针形参要加引用，不然操作的是副本，对实际的root不会产生影响！
*/
const int ALLOWED_IMBALANCE = 1;//最大允许高度差为1
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
    void insert(int v, Node* &nd){//形参是指针的引用！
        if(!nd) nd = new Node(v);
        else if(v < nd->val){
            insert(v, nd->left);
        }else if(v > nd->val){
            insert(v,nd->right);
        }
        nd = balance(nd);
    }
    //右边节点左旋
    Node* rotate2Left(Node* nd){//功能函数且有指针变量返回值（意味着会有重新赋值的操作），不需要加引用
        Node* node = nd->right;
        nd->right = node->left;
        node->left = nd;
         //调整高度
        nd->h = max(hof(nd->right),hof(nd->left))+1;
        node->h = max(hof(node->left),hof(node->right))+1;
        return node;
    }
    //左边节点右旋
    Node* rotate2Right(Node* nd){
        Node* node = nd->left;
        nd->left = node->right;
        node->right = nd;
        //调整高度
        nd->h = max(hof(nd->right),hof(nd->left))+1;
        node->h = max(hof(node->left),hof(node->right))+1;
        return node;
    }
    //对右边节点的双旋转
    Node* double2Left(Node* nd){
        nd->right = rotate2Right(nd->right);
        return rotate2Left(nd);
    }
    //对左边节点的双旋转
    Node* double2Right(Node* nd){
        nd->left = rotate2Left(nd->left);
        return rotate2Right(nd);
    }
    Node* balance(Node* t){//如果没有返回值的操作函数，通常不要忘了加引用！
        if(t == NULL) return t;
        if(hof(t->left) - hof(t->right) > ALLOWED_IMBALANCE){//左边高
            if(hof(t->left->left) >= hof(t->left->right)){//左左型
                t = rotate2Right(t);
            }else{t = double2Right(t);}//左右型
        }else if(hof(t->right) - hof(t->left) > ALLOWED_IMBALANCE){//右边高
            if(hof(t->right->right) >= hof(t->right->left)){//右右型
                t = rotate2Left(t);
            }else{t = double2Left(t);}//右左型
        }
        t->h = max(hof(t->left),hof(t->right))+1;//调整高度
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
