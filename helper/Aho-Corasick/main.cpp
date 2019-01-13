#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
/**
 AC�Զ�����Trie������failָ�루���׺ָ�룩ʵ�ֶ�ģʽƥ��
 hduoj 2222
*/
class AhoCorasick{
private:
    class Node{
    public:
        int cnt;//��صı���ֵ���ɸ�������仯����
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
    //AC�Զ�����ؼ�����������failָ��
    void build(){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* nd = q.front();q.pop();
            for(int i = 0 ; i < 26; i++){
                if(nd->next[i]){
                    if(nd == root) nd->next[i]->fail = root;
                    else{
                        Node* p = nd->fail;//��λ�����׵�ʧ��ָ�루ֻ�и��ڵ��ʧ��ָ����NULL��
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
    //����s�г��ֵ�ģʽ�Ӵ����ܸ���
    int match(string s){
        Node* p = root;
        int res = 0;
        for(int i=0 ; i< s.size(); i++){
            int c = s[i]-'a';
            while(p->next[c]==NULL && p!=root) p = p->fail;
            p = p->next[c];
            p = (p==NULL)?root:p;
            //ͳ�Ƹ���
            Node* tmp = p;
            while(tmp != root && tmp->cnt != -1){
                res += tmp->cnt;
                tmp->cnt = -1;//�Ѿ�ͳ�ƹ�����Ϊ-1,ע������ı�������ֵ����������һ����AC�Զ���
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
