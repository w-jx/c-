#include <iostream>
#include <condition_variable>
#include <thread>
#include <mutex>
#include <ctime>
#include <array>



/*
2021.4.2 用c++ condition_variable实现的生产者消费者模型
小技巧：先创建消费者线程，生产者线程的延时比消费者略大会让输出变得规律

*/
using namespace std;
std::mutex mtx;
std::condition_variable has_product;

std::array<int, 5> myarr;
void producer()
{
    srand((unsigned)time(nullptr));
    int i = 0;
    while (true)
    {
        do
        {
            std::lock_guard<std::mutex> mylock(mtx);
            myarr[i] = rand() % 10 + 1;
            cout << "in producer:arr[" << i << "]=" << myarr[i] << endl;
        } while (false);

        has_product.notify_one();
        std::this_thread::sleep_for(std::chrono::seconds(2)); //生产者的延时可以略大一点，让输出比较规律
        i = (i + 1) % 5;
    }
}
void consumer()
{
    int i = 0;
    while (true)
    {
        do
        {
            std::unique_lock<std::mutex> mylock(mtx);
            has_product.wait(mylock);
        } while (false);

        cout << "--in consumer:arr[" << i << "]=" << myarr[i] << endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        i = (i + 1) % 5;
    }
}
int main()
{
    std::thread t_consu(consumer);
    std::thread t_prod(producer);

    if (t_prod.joinable())
        t_prod.join();
    if (t_consu.joinable())
        t_consu.join();

    return 0;
}