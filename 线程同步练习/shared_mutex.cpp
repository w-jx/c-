#if 1
#include <iostream>
#include <vector>
#include <shared_mutex>
#include <thread>
#include <array>
#include <ctime>
#include <mutex>
using namespace std;

///用 共享锁 实现pthread_rwlock 读写锁的功能
//"std" 没有成员 "shared_mutex" c++17才支持
std::shared_mutex mtx;
std::array<int ,5> myarr;
void write()
{
	int idx=0;
	srand(static_cast<unsigned>(time(nullptr) ));

	while (true) {
		do {
		std::lock_guard<std::shared_lock> mylock(mtx);
		}while (false);

	}
}

void read(int idx)
{

}
int main(void)
{

	thread th[3];
	for(int i=0;i<3;i++) {
		if (i==0) {
			th[i] =thread(write);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
		th[i]=thread(read,i);
	}
	for(int i=0;i<3;i++) {
		if (th[i].joinable())
			th[i].join();
	}
	

	return 0;
}
#endif
