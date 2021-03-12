#if 1
#include <iostream>
#include <vector>
#include <thread>
#include <array>
#include <ctime>
#include <mutex>
#include <pthread.h>

//unistd.h 和std::thread 不能共存
using namespace std;

//用pthread_rwlock 锁 实现了线程同步
/*
write:myarr[4]=98
-----read2:myarr[-----read1:myarr[4]=98
4]=98

读写锁之间的竞争，睡眠时间都是800ms的时候

*/
std::array<int, 5> myarr;
pthread_rwlock_t rwlock;
void write()
{
    int i = 0;
    srand(time(0));
    while (true)
    {
        pthread_rwlock_wrlock(&rwlock);
        std::this_thread::sleep_for(std::chrono::microseconds(800));//这边加延时是为了读锁那边不冲突
        myarr[i] = rand() % 100 + 1;
        cout << "write:myarr[" << i << "]=" << myarr[i] << endl;
        pthread_rwlock_unlock(&rwlock);
        i = (i + 1) % 5;
        std::this_thread::sleep_for(std::chrono::milliseconds(700));
    }
}
void read1()
{
    int i = 0;
    srand(time(0));
    while (true)
    {
        pthread_rwlock_rdlock(&rwlock);
        std::this_thread::sleep_for(std::chrono::microseconds(800));
        cout
            << "-----read1:myarr[" << i << "]=" << myarr[i] << endl;

        pthread_rwlock_unlock(&rwlock);

        i = (i + 1) % 5;
        std::this_thread::sleep_for(std::chrono::milliseconds(700));
    }
}

void read2()
{
    int i = 0;
    srand(time(0));
    while (true)
    {
        pthread_rwlock_rdlock(&rwlock);
        std::this_thread::sleep_for(std::chrono::microseconds(800));
        cout
            << "-----read2:myarr[" << i << "]=" << myarr[i] << endl;

        pthread_rwlock_unlock(&rwlock);

        i = (i + 1) % 5;
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
    }
}

int main(void)
{
    std::thread t_write(write);

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::thread t_read1(read1);
    std::thread t_read2(read2);

    if (t_write.joinable())
        t_write.join();
    if (t_read1.joinable())
        t_read1.join();
    if (t_read2.joinable())
        t_read2.join();

    pthread_rwlock_init(&rwlock, nullptr); //初始化读写锁

    pthread_rwlock_destroy(&rwlock); //销毁读写锁

    //system("pause");
    return 0;
}
#endif