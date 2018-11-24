#include <iostream>
#include <cstring>
using namespace std;
/**
   ���ļ����ֵ���ֻ�漰a-z��26����ĸ���ɸ��ݾ����������next�Ĵ�С
*/
class TrieNode{
    public:
        bool exist;
        TrieNode *next[26];
        TrieNode(){
            exist = false;
            memset(next,0,sizeof(next));
        }
        ~TrieNode(){
            //cout<<"TrieNode�������������ã�"<<endl;
            for(int i = 0 ; i < 26; i++){
                delete next[i];
            }
        }
};
class Trie {
public:
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    ~Trie(){
        //cout<<"Trie���������������ã�"<<endl;
        delete root;
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for(int i = 0 ; i < word.size(); i++){
            if(!p->next[word[i]-'a']) p->next[word[i]-'a'] = new TrieNode();
            p = p->next[word[i]-'a'];
        }
        p->exist = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = find(word);
        return p != NULL && p->exist;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = find(prefix);
        return p != NULL;
    }
private:
    TrieNode* find(string word){
        TrieNode *p = root;
        for(int i = 0; i < word.size() && p ;i++){
            p = p->next[word[i]-'a'];
        }
        return p;
    }
};
//����
int main(){
    Trie obj;
    obj.insert("apple");
    obj.insert("banana");
    obj.insert("watermelon");
    obj.insert("strawberry");
    obj.insert("pear");
    cout<<obj.search("jack")<<endl;
    obj.insert("jack");
    cout<<obj.search("jack")<<endl;
    cout<<obj.search("apple")<<endl;
    cout<<obj.startsWith("ap")<<endl;
    cout<<obj.search("water")<<endl;
    cout<<obj.startsWith("water")<<endl;
}
