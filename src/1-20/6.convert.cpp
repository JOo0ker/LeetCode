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
	length.push_back(0);
	for (size_t i = 0; i < (size_t)numRows - 1 ; i++)
	{
		int tmp1 = nums * ((i == 0 || i == (size_t)numRows - 1 ? 1 : 2));
		int tmp2 = (bool)(remaing > i);
		int tmp3 = (bool)(remaing > (cycle - i));
		length.push_back(tmp1 + tmp2 + tmp3 + length.back());
	}

	for (size_t i = 0; i < s.size(); i++)
	{
		int line = i % cycle;
		if (line >= numRows)line = cycle - line;

		tmpStr[length[line]++] = s[i];
	}
	m_Result.clear();
	m_Result.append(tmpStr);

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
