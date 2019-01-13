#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int k;
void add(int st[], int a[], int i, int n){
    if(i > n-1) return;
    add(st, a, 2*i+1, n);
    st[i] = a[k++];
    add(st, a, 2*i+2, n);
}
int main(){
    scanf("%d",&n);
    int a[n]; int cst[n];
    for(int i = 0 ; i < n ;i ++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    fill(cst, cst+n, -1);
    k = 0;
    add(cst, a, 0, n);
    for(int i = 0 ; i < n; i++){
        if(i == 0) cout<<cst[i];
        else cout<<" "<<cst[i];
    }
}
