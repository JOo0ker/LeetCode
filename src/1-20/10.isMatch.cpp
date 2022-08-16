#include "10.isMatch.h"
//给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
//'.' 匹配任意单个字符
//'*' 匹配零个或多个前面的那一个元素
//所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。


bool isMatch::Solution::isMatch(string s, string p)
{
	if (p.empty()) return s.empty();

	char first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');

	if (p.length() >= 2 && p[1] == '*')
	{
		return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
	}
	else
	{
		return first_match && isMatch(s.substr(1), p.substr(1));
	}
}


void isMatch::test()
{
	string tmp1, tmp2;
	tmp1 = { "ab" };
	tmp2 = { ".*c" };
	isMatch::Solution sol10;
	bool result = sol10.isMatch(tmp1, tmp2);

	std::cout << "s :" << tmp1 << '\n' << "p :" << tmp2 << '\n' << (result ? "true" : "fasle") << '\n';

	while (true)
	{
		std::cout << "Please enter the target string:";
		std::cin >> tmp1;
		std::cout << "Please enter the match string:";
		std::cin >> tmp2;

		result = sol10.isMatch(tmp1, tmp2);
		std::cout << "Result is: " << (result ? "true" : "fasle") << '\n';
	}
}