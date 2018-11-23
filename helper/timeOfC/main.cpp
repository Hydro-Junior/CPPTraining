#include <iostream>
#include <cstdio>
#include <cstdlib> //malloc()、calloc()、realloc()、free()、system()、atoi()、atol()、rand()、srand()、exit()
#include <ctime>
using namespace std;
//c/c++时间库函数
/*
struct tm {
  int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
  int tm_min;   // 分，范围从 0 到 59
  int tm_hour;  // 小时，范围从 0 到 23
  int tm_mday;  // 一月中的第几天，范围从 1 到 31
  int tm_mon;   // 月，范围从 0 到 11
  int tm_year;  // 自 1900 年起的年数
  int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
  int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
  int tm_isdst; // 夏令时
}*/
//4个部分简化记忆：1. time()函数获取时间 2. time_t表示时间 3. tm表示时间的结构体 4. 其他：ctime(time_t*),asctime(tm*),localtime(time_t*),gmtime(time_t*)等都是为转化使用
int main()
{
    clock_t start = clock();//clock_t 实际上是long类型
    cout<<"开始："<<start<<endl;
    time_t now = time(0);//当前系统的时间
    char* dt = ctime(&now); //把now转为字符串形式
    cout<<"本地日期和时间："<< dt << endl;


    //把now 转换为 tm 结构,GMT格林尼治时间
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm); //再把tm结构转为字符串
    //cout<<gmtm->tm_hour<<":"<<gmtm->tm_min<<":"<<gmtm->tm_sec<<endl;
    cout<<"UTC 日期和时间："<< dt<<endl;
    time_t gmnow = mktime(gmtm);
    double diff = difftime(gmnow,now);
    cout<<"两地相差秒数："<<diff<<"分钟数："<<diff/60<<"小时数："<<diff/3600<<endl;

    //把now 转换为 tm 结构,本地时间
    tm *lctm = localtime(&now);
    dt = asctime(lctm);
    cout<<"本地时间："<<dt<<endl;

    //时间格式化输出
    time_t rawtime;
    struct tm *info;
    char buffer[80];
    time(&rawtime);//把当前时间读到rawtime
    info = localtime(&rawtime);//获得时间结构体
    strftime(buffer,80,"%Y-%m-%d %H:%M:%S",info);
    printf("格式化的日期 & 时间：|%s|\n",buffer);

    clock_t end = clock();
    cout<<"结束："<<end<<endl;
    cout<<"程序执行总时间："<<(double)(end - start)/CLOCKS_PER_SEC<<endl;//CLOCK_PER_SEC表示每秒有多少个CPU时钟计时单元
    return 0;
}
