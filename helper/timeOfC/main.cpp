#include <iostream>
#include <cstdio>
#include <cstdlib> //malloc()��calloc()��realloc()��free()��system()��atoi()��atol()��rand()��srand()��exit()
#include <ctime>
using namespace std;
//c/c++ʱ��⺯��
/*
struct tm {
  int tm_sec;   // �룬������Χ�� 0 �� 59���������� 61
  int tm_min;   // �֣���Χ�� 0 �� 59
  int tm_hour;  // Сʱ����Χ�� 0 �� 23
  int tm_mday;  // һ���еĵڼ��죬��Χ�� 1 �� 31
  int tm_mon;   // �£���Χ�� 0 �� 11
  int tm_year;  // �� 1900 ���������
  int tm_wday;  // һ���еĵڼ��죬��Χ�� 0 �� 6��������������
  int tm_yday;  // һ���еĵڼ��죬��Χ�� 0 �� 365���� 1 �� 1 ������
  int tm_isdst; // ����ʱ
}*/
//4�����ּ򻯼��䣺1. time()������ȡʱ�� 2. time_t��ʾʱ�� 3. tm��ʾʱ��Ľṹ�� 4. ������ctime(time_t*),asctime(tm*),localtime(time_t*),gmtime(time_t*)�ȶ���Ϊת��ʹ��
int main()
{
    clock_t start = clock();//clock_t ʵ������long����
    cout<<"��ʼ��"<<start<<endl;
    time_t now = time(0);//��ǰϵͳ��ʱ��
    char* dt = ctime(&now); //��nowתΪ�ַ�����ʽ
    cout<<"�������ں�ʱ�䣺"<< dt << endl;


    //��now ת��Ϊ tm �ṹ,GMT��������ʱ��
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm); //�ٰ�tm�ṹתΪ�ַ���
    //cout<<gmtm->tm_hour<<":"<<gmtm->tm_min<<":"<<gmtm->tm_sec<<endl;
    cout<<"UTC ���ں�ʱ�䣺"<< dt<<endl;
    time_t gmnow = mktime(gmtm);
    double diff = difftime(gmnow,now);
    cout<<"�������������"<<diff<<"��������"<<diff/60<<"Сʱ����"<<diff/3600<<endl;

    //��now ת��Ϊ tm �ṹ,����ʱ��
    tm *lctm = localtime(&now);
    dt = asctime(lctm);
    cout<<"����ʱ�䣺"<<dt<<endl;

    //ʱ���ʽ�����
    time_t rawtime;
    struct tm *info;
    char buffer[80];
    time(&rawtime);//�ѵ�ǰʱ�����rawtime
    info = localtime(&rawtime);//���ʱ��ṹ��
    strftime(buffer,80,"%Y-%m-%d %H:%M:%S",info);
    printf("��ʽ�������� & ʱ�䣺|%s|\n",buffer);

    clock_t end = clock();
    cout<<"������"<<end<<endl;
    cout<<"����ִ����ʱ�䣺"<<(double)(end - start)/CLOCKS_PER_SEC<<endl;//CLOCK_PER_SEC��ʾÿ���ж��ٸ�CPUʱ�Ӽ�ʱ��Ԫ
    return 0;
}
