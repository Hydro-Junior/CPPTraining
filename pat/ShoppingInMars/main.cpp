#include<iostream>
#include<climits>
using namespace std;
/**
    此题用普通思路明显会超时，实际上这是个滑动窗口模型，O(n)时间复杂度即可解决。
*/
static int off =[](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
int main(){
    int n,M,lo = 0,hi = 0,sum = 0,fakeM = INT_MAX;
    bool existSolution = false;
    cin>>n>>M;
    int nums[n];
    for(int i = 0 ; i < n; i++){
        cin>>nums[i];
    }
    for(;hi < n; hi++){
        sum += nums[hi];
        if(sum < M)continue;
        while(lo <= hi && sum >= M){
            fakeM = min(fakeM,sum);
            if(sum == M){
                existSolution = true;
                cout<<(lo+1)<<"-"<<(hi+1)<<endl;
            }
            sum -= nums[lo++];
        }
    }
    sum = 0;
    if(!existSolution){//不存在精确解，fakeM才派上用场，再用一次滑动窗口
        lo = 0; hi = 0;
        for(;hi < n; hi++){
            sum += nums[hi];
            if(sum < fakeM)continue;
            while(lo <= hi && sum >= fakeM){
                if(sum == fakeM){
                    cout<<(lo+1)<<"-"<<(hi+1)<<endl;
                }
                sum -= nums[lo++];
            }
        }
    }
    return 0;
}
