#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;
/**
    普通的多级排序题，注意规则细节就好了，这里懒得加析构函数，没有主动释放堆内存。
*/
static int n = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class User{
public:
    int id,perfectN,sum;
    int *score;
    User(){
        score = new int[6];
        memset(score,-1,sizeof(int)*6);
    }
    bool operator< (const User& other) const{
        if(this->sum != other.sum) return this->sum > other.sum;
        else if(this->perfectN != other.perfectN) return this->perfectN > other.perfectN;
        else return this->id < other.id;
    }
};
void printUser(User& user, int k){
    //printf("%05d",user.id);
    cout<<setfill('0')<<setw(5)<<user.id;
    cout<<" "<<user.sum;
    for(int i = 1 ; i <= k; i++){
        if(user.score[i]==-1) cout<<" -";
        else cout<<" "<<user.score[i];
    }
    cout<<endl;
}
User users[10001];
int N,K,M;
int main(){
    cin>>N>>K>>M;
    vector<User> res;
    int fulls[K+1];
    for(int i = 1 ; i <= K; i++){
        cin>>fulls[i];
    }
    for(int i = 0; i < M; i++){
        int id,title,sc;
        cin>>id>>title>>sc;
        int oldsc = users[id].score[title];
        if(sc == -1 && oldsc == -1) users[id].score[title] = 0;
        if(sc >= 0){
            users[id].id = id;//激活用户可以上榜
            if(sc > oldsc){//只在新值大于旧值时作更新，旧值最初往往是-1
                users[id].score[title] = sc;
                if(oldsc == -1) users[id].sum += sc;
                else users[id].sum += (sc - oldsc);
                if(sc == fulls[title]) users[id].perfectN += 1;
            }
        }
    }
    for(int i = 1; i <= N; i++){
        if(users[i].id != 0){
            res.push_back(users[i]);
        }
    }
    int rank = 1;
    sort(res.begin(),res.end());
    for(int i = 0 ;  i < res.size(); i++){
        if(i > 0 && res[i].sum < res[i-1].sum) rank = i+1;
        cout<<rank<<" ";
        printUser(res[i],K);
    }
    return 0;
}
