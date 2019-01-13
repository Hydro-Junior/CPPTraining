#include<iostream>
#include<cstdio>
#include<set>
#include<iterator>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,num,q,s1,s2;
float res;
int main(){
  scanf("%d",&n);
  set<int> numset[n+1];
  for(int i = 0; i < n; i++){
    scanf("%d",&m);
    for(int j = 0 ; j < m ; j++){
      scanf("%d",&num);
      numset[i+1].insert(num);
    }
  }
  scanf("%d",&q);
  for(int i = 0 ; i < q; i++){
    scanf("%d%d",&s1,&s2);
    vector<int> v1,v2;
    set_union(numset[s1].begin(),numset[s1].end(),numset[s2].begin(),numset[s2].end(),back_inserter(v1));
    set_intersection(numset[s1].begin(),numset[s1].end(),numset[s2].begin(),numset[s2].end(),back_inserter(v2));
    float nc = (float)v2.size();
    float nt = (float)v1.size();
    cout<<"nc:"<<nc<<"  nt: "<<nt<<endl;
    res = nc / nt * 100;
    printf("%.1f",res);
    cout<<"%"<<endl;
  }
  return 0;
}

