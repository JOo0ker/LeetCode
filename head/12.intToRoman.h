#pragma once

#include <string>
#include <map>
#include <iostream>

using std::string;
using std::map;

namespace intToRoman{
	class Solution;
	void test();
};

class intToRoman::Solution
{
public:
	const char* m_MapChar[4][10] = {
	{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
	{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
	{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
	{ "", "M", "MM", "MMM"}
	};

	string m_Result = {};
	string intToRoman(int num);
};