#include "13.romanToInt.h"

#include "12.intToRoman.h"

int romanToInt::Solution::romanToInt(string s)
{
	m_Result = 0;
	std::map<char, int> mapInt;
	mapInt['I'] = 1;
	mapInt['V'] = 5;
	mapInt['X'] = 10;
	mapInt['L'] = 50;
	mapInt['C'] = 100;
	mapInt['D'] = 500;
	mapInt['M'] = 1000;

	for (size_t i = 0; i < s.size(); i++)
	{
		int temp = 0;
		temp = mapInt[s[i]];
		if (i != s.size() - 1)// 不是最后一个元素
		{
			if (mapInt[s[i + 1]] > mapInt[s[i]])// 后一个元素大于前一个元素 4 IX,9 IV
			{
				temp = mapInt[s[i + 1]] - mapInt[s[i]];
				i += 1;
			}
		}
		m_Result += temp;
	}

    return m_Result;
}

void romanToInt::test()
{
	intToRoman::Solution sol12;
	romanToInt::Solution sol13;
	
	int number, result;
	string RomanString = {}, s = {};
	s = { "DCXLIV" };
	result = sol13.romanToInt(s);
	std::cout << s << " -> " << result << '\n';

	while (true)
	{
		std::cout << "Please enter a number to convert into Roman: ";
		std::cin >> number;
		RomanString = sol12.intToRoman(number);
		result = sol13.romanToInt(RomanString);

		std::cout << "The number of " << number << "'s Roman String is :" << RomanString << '\n';
		std::cout << "And it's number is :" << result << '\n';
	}
}


//字符          数值
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000