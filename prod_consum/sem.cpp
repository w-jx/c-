#include <iostream>
#include <semaphore>
#include <thread>
#include <ctime>
#include <array>

using namespace std;
/*
2021/4/2日 复习
利用c++ 20实现的生产者消费者模型
编译：-std=c++2a
//gcc9.3暂时还不支持  已经在vs2019测试通过

*/
std::counting_semaphore prod(5);
std::counting_semaphore consu(0);

std::array<int,5> arr;
void producer()
{
    srand(time(nullptr));
    int i=0;

    while (true) {
        prod.acquire();
        arr[i]=rand()%10;
        cout<<"in producer,arr["<<i<<"]="<<arr[i]<<endl;
        consu.release();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        i = (i+1)%5;   
    }

}
void consumer()
{
 
    int i=0;

    while (true) {
        consu.acquire();
        cout<<"--in consumer,arr["<<i<<"]="<<arr[i]<<endl;
        prod.release();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        i = (i+1)%5;   
    }
}

int main()
{

std::thread t_prod(producer);
std::thread t_consu(consumer);

if (t_prod.joinable())
    t_prod.join();
if (t_consu.joinable())
    t_consu.join();


    return 0;
}