#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#include <semaphore.h> 

#include <time.h>

sem_t prod,consu;

int sums[5]={0};
/*
2021/4/2 复习利用pthread sem的生产者消费者
不需要pthread_mutex_t 
千万注意，信号量的初始化一定要在线程的创建之前
不然会阻塞住

*/
void* producer(void *arg) 
{
    
    srand((unsigned )time(NULL));
    int val  =0,i=0;
    while (1) {
        sem_wait(&prod);
        val = rand()%10;  
        sums[i]=val;
        printf("in producer:sum[i]=%d\n",sums[i]);
        sem_post(&consu);
        sleep(1);
        i=(i+1)%5;
    }
    return NULL;

}
void * consumer(void *arg) 
{

    int i=0;
    srand(time(NULL));
    while (1) {
        sem_wait(&consu);
        printf("--in consumer:sum[i]=%d\n",sums[i]);
        sums[i]=0;
        sem_post(&prod);
        sleep(1);
        i=(i+1)%5;
    }
    return NULL;
}

int main()
{
    pthread_t t_producer,t_consumer;//生产者，消费者线程

    int ret =0;

        ret = sem_init(&prod,0,5);//想象厨师生产菜，初始的时候5个盘子
    if (ret<0)
        perror("sem_init prod error\n");
    ret = sem_init(&consu,0,0);//想象消费者消费菜，初始的时候0道菜可以吃
    if (ret<0)
        perror("sem init consu error\n");

    ret  =pthread_create(&t_producer,NULL,producer,NULL);
    if(ret<0) 
        perror("pthread_create error\n");
    
    ret = pthread_create(&t_consumer,NULL,consumer,NULL);
    if (ret<0)
        perror("pthread_create consu error\n");
    pthread_join(&t_producer,NULL);
    pthread_join(&t_consumer,NULL);
    //初始化条件标量
  



    sem_destroy(&prod);
    sem_destroy(&consu);


    return 0;

}