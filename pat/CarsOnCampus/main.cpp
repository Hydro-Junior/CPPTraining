#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
#include<cstdio>
using namespace std;
class Record{
public:
    string plate;
    int time;
    int state;//0-进 1-出
    bool operator<(const Record& r){
        if(this->plate != r.plate) return this->plate < r.plate;
        else if(this->time != r.time) return this->time < r.time;
        else return this->state < r.state;
    }
};
bool match(const Record& r1, const Record &r2){
    return r1.plate==r2.plate && r1.state==0 && r2.state==1;
}
int getTime(int h , int m ,int s){
    return h*3600 + m*60 + s;
}
void printTime(int time){
    printf("%02d:%02d:%02d",time/3600,time/60%60,time%60);
}
int main(){
    int n , q;
    cin>>n>>q;
    Record rc[n];
    int timeTable[24*3600];
    memset(timeTable,0,sizeof(timeTable));
    map<string,int> delaymap;
    for(int i = 0 ; i < n; i++){
        string tp; cin>>tp;
        int h, m , s;
        scanf("%d:%d:%d",&h,&m,&s);
        string ts; cin>>ts;
        int io = (ts=="in" ? 0 : 1);
        rc[i].plate = tp;
        rc[i].time = getTime(h,m,s);
        rc[i].state = io;
    }
    sort(rc,rc+n);
    for(int i = 0 ; i < n; i++){
        cout<<rc[i].plate<<" "<<rc[i].time<<" "<<rc[i].state<<endl;
    }
    int maxRange = 0;
    for(int i = 0 ; i < n; ){
        if(i < n-1 && match(rc[i],rc[i+1])){//同车in-out成对出现
            delaymap[rc[i].plate] += rc[i+1].time - rc[i].time;
            timeTable[rc[i].time]++;
            timeTable[rc[i+1].time]--;
            if(delaymap[rc[i].plate] > maxRange) maxRange = delaymap[rc[i].plate];
            i += 2;
        }else{
            i++;
        }
    }
    //构造前缀和
    for(int i = 1; i < 24*3600; i++){
        timeTable[i] += timeTable[i-1];
    }
    //查询
    for(int i = 0; i < q; i++){
        int h, m , s;
        scanf("%d:%d:%d",&h,&m,&s);
        cout<<timeTable[getTime(h,m,s)]<<endl;
    }
    for(map<string,int>::iterator it = delaymap.begin(); it != delaymap.end(); it++){
        if(it->second == maxRange)cout<<it->first<<" ";
    }
    printTime(maxRange);
    return 0;
}
