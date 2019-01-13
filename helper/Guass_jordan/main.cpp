#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/**
    ���������Է��������⣺��˹��Ԫ��������Ԫ��
*/
const double EPS = 1E-8;
typedef vector<double> vec;//������
typedef vector<vec> mat;//����
/**
    ���Ax=b,����A�Ƿ��󣬵��������޽����������ʱ���Ż�һ������Ϊ0������
*/
void printMt(const mat& mx){
    cout<<"x    "<<"y   "<<"z   "<<"b   "<<endl;
    for(int i = 0 ; i < mx.size() ; i ++){
        for(int j = 0 ; j < mx[0].size(); j++ )
            cout<<mx[i][j]<<"   ";
        cout<<endl;
    }
    cout<<endl;
}
vec gauss_jordan(const mat& A, const vec& b){
    int n = A.size();//���̵ĸ�����Ҳ�Ǿ��������
    mat B(n,vec(n+1)); //n�У�ÿ��n+1�У�����b�����У�
    //������ֵ
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < n; j++){
            B[i][j] = A[i][j];
        }
    }
    for(int i = 0; i < n ; i ++){
        B[i][n] = b[i];
    }
    for(int i = 0 ; i < n; i++){
        //��Ҫ��ȥ��δ֪��ϵ���ľ���ֵ����ʽ�ӻ�����i��
        int pivot = i;
        for(int j = i ; j < n; j++){
            if(abs(B[j][i]) > abs(B[pivot][i])) pivot = j;//��i�ж�Ӧ��i����Ԫ
        }
        swap(B[i],B[pivot]);
        if(abs(B[i][i]) < EPS) return vec();//�޽����������
        for(int j = i+1; j <= n; j++){
            B[i][j] /= B[i][i];
        }
        for(int j = 0 ; j < n ; j++){
            if(i != j) {
                for(int k = i+1; k <= n; k++){
                    //�ӵ�j��ʽ������ȥ��i��δ֪��
                    B[j][k] -= B[j][i] * B[i][k];
                }
            }
        }
        printMt(B);
    }
    vec x(n);
    for(int i = 0 ; i < n ; i++){
        x[i] = B[i][n];
    }
    return x;
}
int main()
{
    cout<<sizeof(bool)<<" "<<sizeof(char)<<" "<<endl;
    double b[3] = {6,12,21};
    double x[3][3] = {{1,-2,3},{4,-5,6},{7,-8,10}};
    vec vb(b,b+3);
    mat mx(3);
    for(int i = 0 ; i < mx.size() ; i ++){
        vec vx(x[i],x[i] + 3);
        mx[i] = vx;
    }
    cout<<"�������:"<<endl;
    cout<<"x    "<<"y   "<<"z   "<<"b   "<<endl;
    for(int i = 0 ; i < 3 ; i ++){
        cout<<mx[i][0]<<"   "<<mx[i][1]<<"   "<<mx[i][2]<<"   "<<vb[i]<<endl;
    }
    vec res = gauss_jordan(mx,vb);
    cout<<"��ӡ��������"<<endl;
    for(vec::iterator it = res.begin(); it != res.end(); it++){
        cout<<*it<<"    ";
    }
    return 0;
}
