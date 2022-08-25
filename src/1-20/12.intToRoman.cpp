#include "12.intToRoman.h"

//罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。
//
//字符          数值
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X  + II 。 27 写做  XXVII, 即为 XX  + V  + II 。
//
//通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
//
//I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
//X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
//C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
//给你一个整数，将其转为罗马数字。



string intToRoman::Solution::intToRoman(int num)
{
	if (!m_Result.empty())m_Result.clear();



	m_Result.append(m_MapChar[3][num / 1000 % 10]);
	m_Result.append(m_MapChar[2][num / 100 % 10]);
	m_Result.append(m_MapChar[1][num / 10 % 10]);
	m_Result.append(m_MapChar[0][num % 10]);

	return m_Result;
}

void intToRoman::test()
{
	intToRoman::Solution sol12;
	size_t num = 88;
	string result = sol12.intToRoman(num);
	std::cout << num << "->" << result << "\n";

	while (true)
	{
		std::cout << "Please enter a num:";
		std::cin >> num;
		result = sol12.intToRoman(num);
		std::cout << num << "->" << result << "\n";
	}

}
