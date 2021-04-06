#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>


/*
2021/4/2 复习 利用pthread_cond_t条件变量实现的生产者消费者代码

*/
pthread_mutex_t mtx;
pthread_cond_t has_product;
int arr[5] = {0};
void sys_err(const char *str)
{
    perror(str);
    exit(0);
}
void *producer(void *arg)
{

    srand((unsigned)time(NULL));
    int i = 0;
    while (1)
    {
        pthread_mutex_lock(&mtx);
        arr[i] = rand() % 10 + 1;
        printf("in producer,arr[%d]=%d\n", i, arr[i]);
        pthread_mutex_unlock(&mtx);
        pthread_cond_signal(&has_product);
        sleep(2);
        i = (i + 1) % 5;
    }
    return NULL;
}
void *consumer(void *arg)
{
    int i = 0;
    while (1)
    {
        pthread_mutex_lock(&mtx);
        pthread_cond_wait(&has_product, &mtx);
        printf("--in consumer,arr[%d]=%d\n", i, arr[i]);
        pthread_mutex_unlock(&mtx);
        sleep(1);
        i = (i + 1) % 5;
    }
    return NULL;
}

int main()
{
    pthread_t t_prod, t_consu;
    int ret = 0;
    ret = pthread_mutex_init(&mtx, NULL);
    if (ret != 0)
        sys_err("init mtx error\n");
    ret = pthread_cond_init(&has_product, NULL); //初始化锁 和条件变量
    if (ret != 0)
        sys_err("cond init error\n");

    ret = pthread_create(&t_consu, NULL, consumer, NULL);
    if (ret != 0)
        sys_err("pthread create consu error\n");

    ret = pthread_create(&t_prod, NULL, producer, NULL);
    if (ret != 0)
        sys_err("pthread_create prod error\n");

    pthread_join(&t_prod, NULL);
    pthread_join(&t_consu, NULL);

    pthread_cond_destroy(&has_product);

    return 0;
}