#include<cstdio>
#include<algorithm>
#include<unordered_map>
using namespace std;
int N,M,a[100000];
int main(){
    scanf("%d%d",&N,&M);
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+N);
    bool hasSolution = false;
    unordered_map<int,int> mp;
    int n1,n2;
    for(int i = 0 ; i < N; i++){
        if(a[i] > M) break;
        if(mp.count(M-a[i])){
            hasSolution = true;
            n1 = M - a[i];
            n2 = a[i];
        }
        mp[a[i]]++;
    }
    if(hasSolution){
        printf("%d %d\n",n1,n2);
    }else{
        printf("No Solution\n");
    }
    return 0;
}
