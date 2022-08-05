#include "3.lengthOfLongestSubstring.h"

int lengthOfLongestSubstring::Solution::lengthOfLongestSubstring(string s)
{
	size_t totalLength = s.length();
	if (!totalLength) return 0;
	m_Result = 1;
	m_SubString.clear();
 	m_SubString.push_back(s[0]);
	int tmpLength = 1;
	for (int i = 1; i < totalLength; ++i)
	{
		int pos = check(s[i]);
		if (pos == -1)
		{
			tmpLength += 1;
		}
		else
		{
			tmpLength -= pos;
			m_SubString.erase(0, (size_t)pos + 1);
		}
		m_SubString.push_back(s[i]);
		m_Result = (tmpLength > m_Result ? tmpLength : m_Result);
	}
	return m_Result;
}

int lengthOfLongestSubstring::Solution::check(char c)
{
	return static_cast<int>(m_SubString.find_first_of(c));
}


void lengthOfLongestSubstring::test()
{
	string s0 = "";
	string s1 = "au";
	string s2 = "bbbbb";
	string s3 = "abcabcbb";

	lengthOfLongestSubstring::Solution sol3;
	int Result = sol3.lengthOfLongestSubstring(s0);
	std::cout << Result << '\n';
	Result = sol3.lengthOfLongestSubstring(s1);
	std::cout << Result << '\n';
	Result = sol3.lengthOfLongestSubstring(s2);
	std::cout << Result << '\n';
	Result = sol3.lengthOfLongestSubstring(s3);
	std::cout << Result << '\n';
}