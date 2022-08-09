#include "8.myAtoi.h"

//   -> 32
// 0 -> 48
// 9 -> 57
// + -> 43
// - -> 45

int myAtoi::Solution::myAtoi(string s)
{
	if (!s.size()) return 0;
	
	size_t pos = 0;
	while (s[pos] == ' ') pos++;

	bool isNeg = false;

	if (s[pos] == '+') { isNeg = false; pos++; }
	else if (s[pos] == '-') { isNeg = true; pos++; }

	for (; pos < s.size() && s[pos] >= '0' && s[pos] <= '9'; pos++)
	{
		m_Result = m_Result * 10 + ((long long)s[pos] - '0');
		if (!isNeg && m_Result > INT_MAX) return INT_MAX;
		if (isNeg && -m_Result < INT_MIN) return INT_MIN;
	}


	return isNeg ? -m_Result : m_Result;
}

void myAtoi::test()
{
	myAtoi::Solution sol8;
	int result = sol8.myAtoi("   9999999999");
	
	std::cout << result << '\n';
}
