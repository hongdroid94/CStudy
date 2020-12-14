#include "stdafx.h"
#include <iostream>
using namespace std;
/**
 * 함수 포인터 예제
 */
class Tipsware
{
private:
	int m_data;

public:
	Tipsware()
	{
		m_data = 0;
	}

	void setData(int a_data)
	{
		m_data = a_data;
	}

	void showData()
	{
		cout << "data : " << m_data << endl;
	}
};


int main()
{
	Tipsware data;
	// Tipsware 클래스의 setData 함수 주소를 저장하는 포인터 선언
	void (Tipsware::*pTips)(int) = &Tipsware::setData; 
	//data.setData(5); 랑 동일하다.
	(data.*pTips)(5);
	
	data.showData();
    return 0;
}

