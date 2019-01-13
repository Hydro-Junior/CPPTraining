#include<cstdio>
#include<stack>
using namespace std;
int M,N,K;
int main(){
    scanf("%d%d%d",&M,&N,&K);
    int a[N];
    for(int i = 0 ; i < K ; i++){
        stack<int> stk;
        for(int j = 0 ; j < N ; j++){
            scanf("%d",&a[j]);
        }
        int k = 0,t = 1;
        for( ; k < N ; k++){
            if(!stk.empty() && stk.top()==a[k]){
                stk.pop();
                continue;
            }else if(!stk.empty() && stk.top()>a[k]){
                printf("NO\n");
                break;
            }
            while(t != a[k]){
                stk.push(t++);
            }
            stk.push(t++);
            if(stk.size() > M){
                printf("NO\n");
                break;
            }else{
                stk.pop();
            }
        }
        if(k == N)printf("YES\n");
    }
    return 0;
}
