#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
/**
 * MUTEX ��Ƽ ������ ����ȭ ����
 */
int value;
mutex value_mutex;

void increase_value()
{
	// Mutex�� Ȱ���� ��Ƽ ������ ����ȭ
	value_mutex.lock(); // lock�� �ɷ��ִ� ������ �ٸ� thread�� �ڵ带 �����������ϰ� ����
	for (int i = 0; i < 10; i++)
	{
		value++;
		cout << value << endl;
	}
	value_mutex.unlock(); // unlock �������� �ɷ��ִ� ���� �����Ѵ�.
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

