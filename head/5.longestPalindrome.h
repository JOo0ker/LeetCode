#pragma once

#include <string>
#include <iostream>

using std::string;

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

