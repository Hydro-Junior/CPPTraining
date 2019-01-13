#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/**
    基本的线性方程组的求解：高斯消元法（列主元）
*/
const double EPS = 1E-8;
typedef vector<double> vec;//横向量
typedef vector<vec> mat;//矩阵
/**
    求解Ax=b,其中A是方阵，当方程组无解或有无穷多解时，放回一个长度为0的数组
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
    int n = A.size();//方程的个数，也是矩阵的行数
    mat B(n,vec(n+1)); //n行，每行n+1列（包括b向量列）
    //参数赋值
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < n; j++){
            B[i][j] = A[i][j];
        }
    }
    for(int i = 0; i < n ; i ++){
        B[i][n] = b[i];
    }
    for(int i = 0 ; i < n; i++){
        //把要消去的未知数系数的绝对值最大的式子换到第i行
        int pivot = i;
        for(int j = i ; j < n; j++){
            if(abs(B[j][i]) > abs(B[pivot][i])) pivot = j;//第i行对应第i个主元
        }
        swap(B[i],B[pivot]);
        if(abs(B[i][i]) < EPS) return vec();//无解或无穷多个解
        for(int j = i+1; j <= n; j++){
            B[i][j] /= B[i][i];
        }
        for(int j = 0 ; j < n ; j++){
            if(i != j) {
                for(int k = i+1; k <= n; k++){
                    //从第j个式子中消去第i个未知数
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
    cout<<"输入矩阵:"<<endl;
    cout<<"x    "<<"y   "<<"z   "<<"b   "<<endl;
    for(int i = 0 ; i < 3 ; i ++){
        cout<<mx[i][0]<<"   "<<mx[i][1]<<"   "<<mx[i][2]<<"   "<<vb[i]<<endl;
    }
    vec res = gauss_jordan(mx,vb);
    cout<<"打印计算结果："<<endl;
    for(vec::iterator it = res.begin(); it != res.end(); it++){
        cout<<*it<<"    ";
    }
    return 0;
}
