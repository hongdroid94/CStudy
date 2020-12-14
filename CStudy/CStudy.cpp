#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
/**
 * MUTEX 멀티 스레딩 동기화 예제
 */
int value;
mutex value_mutex;

void increase_value()
{
	// Mutex를 활용한 멀티 스레딩 동기화
	value_mutex.lock(); // lock이 걸려있는 동안은 다른 thread가 코드를 수행하지못하게 막음
	for (int i = 0; i < 10; i++)
	{
		value++;
		cout << value << endl;
	}
	value_mutex.unlock(); // unlock 시점에서 걸려있던 락을 해제한다.
}


int main()
{
	value = 0;
	thread thread1(increase_value);
	thread thread2(increase_value);

	thread1.join();
	thread2.join();

    return 0;
}

