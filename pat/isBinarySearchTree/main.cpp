#include<iostream>
using namespace std;
static int n = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int v):val(v),left(NULL),right(NULL){}
};
class BST{
public:
    Node* root;
    BST():root(NULL){}
    void insert(int v){
        insert(v ,root);
    }
private:
    void insert(int v, Node* &root){
        if(root == NULL) {root = new Node(v); return;}
        if(v < root->val){
            insert(v, root->left);
        }else{
            insert(v, root->right);
        }
    }
};
int N,k;
void preOrderLeft(Node* root,int arr[]){
    if(root == NULL) return;
    arr[k++] = root->val;
    preOrderLeft(root->left,arr);
    preOrderLeft(root->right,arr);
}
void preOrderRight(Node* root,int arr[]){
    if(root == NULL) return;
    arr[k++] = root->val;
    preOrderRight(root->right,arr);
    preOrderRight(root->left,arr);
}
void postOrderLeft(Node* root){
    if(root == NULL) return;
    postOrderLeft(root->left);
    postOrderLeft(root->right);
    if(k++ == 0) cout<<root->val;
    else cout<<" "<<root->val;
}
void postOrderRight(Node* root){
    if(root == NULL) return;
    postOrderRight(root->right);
    postOrderRight(root->left);
    if(k++ == 0) cout<<root->val;
    else cout<<" "<<root->val;
}
int main(){
    BST bst;
    cin>>N;
    int arr[N],left[N],right[N];
    for(int i = 0 ; i < N ;i++){
        cin>>arr[i];
        bst.insert(arr[i]);
    }
    k = 0;
    preOrderLeft(bst.root,left);k = 0;
    preOrderRight(bst.root,right);k = 0;
    bool isL = true,isR = true;
    for(int i = 0 ; i < N ; i++){
        if(left[i] != arr[i]){
            isL = false;
            break;
        }
    }
    if(!isL){
        for(int i = 0 ; i < N ; i++){
            if(right[i] != arr[i]){
                isR = false;
                break;
            }
        }
    }
    if(!isL && !isR){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        if(isL){
            postOrderLeft(bst.root);
        }else{
            postOrderRight(bst.root);
        }
    }
    return 0;
}
