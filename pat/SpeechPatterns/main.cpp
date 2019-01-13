#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
/**
    最多重复出现的单词（不区分大小写），简单题
*/
string input,tmp;
int mfreq;
bool isAlphaNumerical(char c){
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
char toLow(char c){
    if(c >= 'A' && c <= 'Z') return c + ('a'-'A');
    return c;
}
int main(){
    getline(cin,input);
    map<string,int> tb;
    int i = 0;
    while(i < input.size()){
        while(i < input.size() && isAlphaNumerical(input[i])){
            tmp += toLow(input[i++]);
        }
        if(tmp != "") {
            tb[tmp]++;
            if(tb[tmp] > mfreq) mfreq = tb[tmp];
        }
        tmp = "";
        i++;
    }
    for(map<string,int>::iterator it = tb.begin(); it != tb.end(); it++){
        if(it->second == mfreq){
            cout<<it->first<<" "<<mfreq<<endl;
            break;
        }
    }
    return 0;
}
