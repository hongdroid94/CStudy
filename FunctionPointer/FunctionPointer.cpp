#include "stdafx.h"
#include <iostream>
using namespace std;
/**
 * �Լ� ������ ����
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
	// Tipsware Ŭ������ setData �Լ� �ּҸ� �����ϴ� ������ ����
	void (Tipsware::*pTips)(int) = &Tipsware::setData; 
	//data.setData(5); �� �����ϴ�.
	(data.*pTips)(5);
	
	data.showData();
    return 0;
}

