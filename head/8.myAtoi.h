#pragma once

#include <string>
#include <iostream>

using std::string;

namespace myAtoi {
	class Solution;
	void test();
}

class myAtoi::Solution
{
public:
	long long m_Result = 0;
	int myAtoi(string s);
};

