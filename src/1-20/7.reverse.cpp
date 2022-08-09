#include "7.reverse.h"

int reverse::Solution::reverse(int x)
{
	if (x < 10 && x > -10)return x;

	bool isOutofRange = false;
	m_Result = 0;
	while (x/10)
	{
		int tmp = m_Result * 10 + x % 10;
		x /= 10;
		m_Result = tmp;
	}

	if (m_Result > (INT_MAX / 10) || m_Result < (INT_MIN / 10)) return 0;
	if (m_Result == INT_MAX && x > INT_MAX % 10)return 0;
	if (m_Result == INT_MIN && x < INT_MIN % 10)return 0;

	m_Result = m_Result * 10 + x;

	return m_Result;
}

void reverse::test()
{
	reverse::Solution sol7;
	int num = 0;
	std::cout << "The 0 input :" << sol7.reverse(num) << '\n';

	while (true)
	{
		std::cout << "Enter the number:";
		std::cin >> num;
		int result = sol7.reverse(num);

		std::cout << "The reverse is:" << result << '\n';
	}
}
