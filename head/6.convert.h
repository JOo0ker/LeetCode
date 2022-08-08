#pragma once

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

namespace convert {
	class Solution;
	void test();
}

class convert::Solution
{
public:
	string m_Result;
	string convert(string s, int numRows);
};

