#pragma once

#include <string>
#include <iostream>

using std::string;

namespace lengthOfLongestSubstring {
	class Solution;
	void test();
}

class lengthOfLongestSubstring::Solution
{
public:
	int m_Result = 0;
	string m_SubString = {};

	int lengthOfLongestSubstring(string s);

	int check(char c);
};