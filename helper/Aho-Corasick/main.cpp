#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
/**
 AC自动机，Trie树引入fail指针（最长后缀指针）实现多模式匹配
 hduoj 2222
*/
class AhoCorasick{
private:
    class Node{
    public:
        int cnt;//相关的变量值，可根据情况变化类型
        Node* next[26];
        Node* fail;
        Node(){
            cnt = 0;
            fail = NULL;
            memset(next,0,sizeof(next));
        }
        ~Node(){
            for(int i = 0 ; i < 26; i++){
                delete next[i];
            }
        }
    };
public:
    Node* root;
    AhoCorasick(){
        root = new Node();
    }
    ~AhoCorasick(){
        delete root;
    }
    void insert(string s){
        Node* nd = root;
        for(int i = 0 ; i < s.size(); i++){
            int idx = s[i]-'a';
            if(!nd->next[idx]) nd->next[idx] = new Node();
            nd = nd->next[idx];
        }
        nd->cnt ++;
    }
    //AC自动机最关键操作，构造fail指针
    void build(){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* nd = q.front();q.pop();
            for(int i = 0 ; i < 26; i++){
                if(nd->next[i]){
                    if(nd == root) nd->next[i]->fail = root;
                    else{
                        Node* p = nd->fail;//定位到父亲的失败指针（只有根节点的失败指针是NULL）
                        while(p){
                            if(p->next[i]){
                                nd->next[i]->fail = p->next[i];
                                break;
                            }
                            p = p->fail;
                        }
                        if(p == NULL) nd->next[i]->fail = root;
                    }
                    q.push(nd->next[i]);
                }
            }
        }
    }
    //返回s中出现的模式子串的总个数
    int match(string s){
        Node* p = root;
        int res = 0;
        for(int i=0 ; i< s.size(); i++){
            int c = s[i]-'a';
            while(p->next[c]==NULL && p!=root) p = p->fail;
            p = p->next[c];
            p = (p==NULL)?root:p;
            //统计个数
            Node* tmp = p;
            while(tmp != root && tmp->cnt != -1){
                res += tmp->cnt;
                tmp->cnt = -1;//已经统计过，置为-1,注意这里改变了属性值，所以这是一次性AC自动机
                tmp = tmp->fail;
            }
        }
        return res;
    }
};
int g,n;
string text;
string str[10000];
int main()
{
    scanf("%d",&g);
    while(g--){
        scanf("%d",&n);
        AhoCorasick ac;
        for(int i = 0 ; i < n ;i++){
            cin>>str[i];
            ac.insert(str[i]);
        }
        cin>>text;
        ac.build();
        cout<<ac.match(text)<<endl;
    }
    return 0;
}
