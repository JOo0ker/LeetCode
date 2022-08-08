#include "6.convert.h"

string convert::Solution::convert(string s, int numRows)
{
	if (numRows <=0 ) return "error";
	if (numRows == 1
		|| s.size() <= numRows
		|| s.size() == 0) return s;

	size_t cycle = ((size_t)numRows - 1) * 2;
	size_t remaing = s.size() % cycle;
	size_t nums = s.size() / cycle;

	string tmpStr;
	tmpStr.resize(s.size());

	vector<int> length;

	for (int i = 1; i < numRows - 1; i++)
	{
		length.push_back(nums * 2 + (bool)(remaing >= i) +(bool)(remaing >= (2 * numRows - i)));
	}
	length.push_back(nums + remaing >= numRows);

	for (size_t i = 0; i < s.size();)
	{
		for (size_t var : length)
		{
			tmpStr[i + i / (size_t)numRows + var] = s[i++];
		}
	}


	return m_Result;
}

void convert::test()
{
	convert::Solution sol6;

	string str = "";
	int num = 0;
	std::cout << "The emtpyStr/1 input :" << sol6.convert(str, 1) << '\n';
	std::cout << "The \"test\"/0 input :" << sol6.convert("test", 0) << '\n';
	sol6.convert("qweqeeqewqadzxcz123", 4);

	while (true)
	{
		std::cout << "Enter a line:";
		std::cin >> str;
		std::cout << "Enter the numRows:";
		std::cin >> num;
		string result = sol6.convert(str, num);

		std::cout << "The convert is:" << result << '\n';
	}
}
