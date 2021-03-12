#if 1
#include <iostream>
#include <vector>
#include <thread>
#include <array>
#include <ctime>
#include <mutex>
#include <pthread.h>
#include <unistd.h>
using namespace std;

//用pthread_mutex 锁 实现了线程同步
std::array<int, 5> myarr;
pthread_mutex_t mtx;
void *producer(void *arg)
{
    int i = 0;
    srand(time(0));
    while (true)
    {
        pthread_mutex_lock(&mtx);
        myarr[i]=rand()%100+1;
        cout<<"producer,myarr["<<i<<"]="<<myarr[i]<<endl;
        pthread_mutex_unlock(&mtx);
        i = (i + 1) % 5;
        usleep(1000*700);
        
    }
}
void* consumer(void *arg)
{
    int i = 0;
    srand(time(0));
    while (true)
    {
        pthread_mutex_lock(&mtx);
      
        cout<<"-----consumer,myarr["<<i<<"]="<<myarr[i]<<endl;
        pthread_mutex_unlock(&mtx);
        
        i = (i + 1) % 5;
        usleep(1000*700);

        //i = (i + 1) % 5;
      
    }
}
int main(void)
{
    int ret=0;
    ret = pthread_mutex_init(&mtx,nullptr);//初始化锁,参数2是锁的属性，有普通锁，嵌套锁，检错锁，适应锁
    if (ret!=0) {
        perror("init mutex occered error\n");
        exit(0);
    }
    
    pthread_t t_producer,t_consumer;
    ret = pthread_create(&t_producer,nullptr,producer,nullptr);
    if (ret!=0) exit(0);
    usleep(1000*100);
    ret=pthread_create(&t_consumer,nullptr,consumer,nullptr);
    if (ret!=0) exit(0);

    ret = pthread_join(t_producer,nullptr);
    if (ret!=0) exit(0);
    ret = pthread_join(t_consumer,nullptr);
    if (ret!=0) exit(0);

    pthread_mutex_destroy(&mtx);
    system("pause");
    return 0;
}
#endif