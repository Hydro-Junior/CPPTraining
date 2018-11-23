#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;

/**
	把给定的一串数据，填入一个给定了结构的二叉搜索树（题目不难，旨在熟悉c++指针编程与动态内存分配）
*/
int seq;
struct Node{
    int idx;
    Node* left;
    Node* right;
    Node():idx(0),left(NULL),right(NULL){}
};
//按中序为二叉搜索树标记大小序号
void mark(Node* root){
    if(root == NULL) return;
    mark(root->left);
    root->idx = seq++;
    mark(root->right);
}
int main(){
    int n ;
    scanf("%d",&n);
    Node* nodes[n];
    for(int i = 0 ; i < n ;i++){
        nodes[i] = new Node();//动态分配内存
    }
    Node* root = nodes[0];
    for(int i = 0 ; i < n; i++){
        int l;
        int r;
        scanf("%d%d",&l,&r);
        nodes[i]->left = (l==-1? NULL : nodes[l]);
        nodes[i]->right = (r==-1? NULL : nodes[r]);
    }
    int nums[n];
    for(int i = 0 ; i < n; i++){
        scanf("%d",&nums[i]);
    }
    sort(nums,nums+n);
    //为搜索树标记大小顺序idx，利用中序遍历：左中右
    seq = 0;
    mark(root);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* nd = q.front();q.pop();
        if(nd == root)cout<<nums[nd->idx];
        else cout<<" "<<nums[nd->idx];
        if(nd->left != NULL) q.push(nd->left);
        if(nd->right != NULL) q.push(nd->right);
    }
	delete []nodes;
    return 0;
}
