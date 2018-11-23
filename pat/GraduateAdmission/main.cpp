#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int N,M,K,ge,gi;
struct Student{
    float Ge;
    int idx;
    float G;
    vector<int> schools;
    bool operator<(const Student &s)const{
        if(G != s.G) return  G < s.G;
        else if(Ge != s.Ge) return Ge < s.Ge;
        else return idx > s.idx;
    }
};
/*调试用
ostream &operator<<(ostream &os,const Student &item){
    os << "student["<<item.idx<<"]  G:"<<item.G<<"  Ge:"<<item.Ge;
    return os;
}*/
struct School{
    int quata;
    vector<int> admmited;//录取学生名单
};
bool equals(const Student &s1, const Student &s2){
    return s1.G == s2.G && s1.Ge == s2.Ge;
}
int main(){
    scanf("%d%d%d",&N,&M,&K);
    Student stu[N];
    School sch[M];
    priority_queue<Student> pq;
    int ks;
    for(int i = 0 ; i < M; i++){
        scanf("%d",&(sch[i].quata));
    }
    for(int i = 0 ; i < N; i++){
        scanf("%d%d",&ge,&gi);
        stu[i].Ge = ge;
        stu[i].G = (stu[i].Ge + gi)/2;
        stu[i].idx = i;
        for(int j = 0 ; j < K; j++){
            scanf("%d",&ks);
            stu[i].schools.push_back(ks);
        }
        pq.push(stu[i]);
    }
    /*打印排序结果，调试用
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }*/
    while(!pq.empty()){
        Student tmp = pq.top();pq.pop();
        int k = 0;
        while(k < K){
            int id = tmp.schools[k];
            if(sch[id].quata > 0){
                sch[id].admmited.push_back(tmp.idx);
                sch[id].quata--;
                break;
            }else{
                int sid = sch[id].admmited.back();
                if(equals(stu[sid],tmp)){
                    sch[id].admmited.push_back(tmp.idx);
                    sch[id].quata--;
                    break;
                }
            }
            k++;
        }
    }
    for(int i = 0 ; i< M; i++){
        sort(sch[i].admmited.begin(),sch[i].admmited.end());
        for(vector<int>::iterator ite = sch[i].admmited.begin(); ite != sch[i].admmited.end(); ite++){
            if(ite == sch[i].admmited.begin())cout<<*ite;
            else cout<<" "<<*ite;
        }
        cout<<endl;
    }

    return 0;
}
