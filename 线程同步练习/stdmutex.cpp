#if 1
#include <iostream>
#include <vector>
#include <thread>
#include <array>
#include <ctime>
#include <mutex>
using namespace std;

//用std::mutex 锁 实现了线程同步
std::array<int, 5> myarr;
std::mutex mtx;
void producer()
{
    int i = 0;
    srand(time(0));
    while (true)
    {
        do
        {
            std::lock_guard<std::mutex> mylock(mtx);
            myarr[i] = rand() % 100 + 1;
            cout<<"producer:myarr["<<i<<"]="<<myarr[i]<<endl;

        } while (false);

        i = (i + 1) % 5;
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
    }
}
void consumer()
{
    int i = 0;
    srand(time(0));
    while (true)
    {
        do
        {
            std::lock_guard<std::mutex> mylock(mtx);
            cout<<"----consumer:myarr["<<i<<"]="<<myarr[i]<<endl;

        } while (false);

        i = (i + 1) % 5;
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
    }
}
int main(void)
{
    std::thread t_producer(producer);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::thread t_consumer(consumer);

    if (t_producer.joinable())
        t_producer.join();
    if (t_consumer.joinable())
        t_consumer.join();

    system("pause");
    return 0;
}
#endif