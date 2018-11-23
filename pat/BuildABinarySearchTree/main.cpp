#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;

/**
	�Ѹ�����һ�����ݣ�����һ�������˽ṹ�Ķ�������������Ŀ���ѣ�ּ����Ϥc++ָ�����붯̬�ڴ���䣩
*/
int seq;
struct Node{
    int idx;
    Node* left;
    Node* right;
    Node():idx(0),left(NULL),right(NULL){}
};
//������Ϊ������������Ǵ�С���
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
        nodes[i] = new Node();//��̬�����ڴ�
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
    //Ϊ��������Ǵ�С˳��idx���������������������
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
