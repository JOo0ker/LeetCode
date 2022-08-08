#pragma once

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

namespace longestPalindrome {
	class Solution;
	void test();
}


class longestPalindrome::Solution
{
public:
	string m_Result;
	string m_SubString;

	string longestPalindrome(string s);
};

