#include "5.longestPalindrome.h"

string longestPalindrome::Solution::longestPalindrome(string s)
{
	if (!s.size()) return string("");// ¿Õ
	if (s.size() == 1) return s;// a

	int	 pos = 0 // ×Ó×Ö·û´®Î»ÖÃ
		, pos2 = 1// Ô­×Ö·û´®Î»ÖÃ
		, rePos = 0
		, total = s.size();

	string lastString = {}, tmpString = {};

	bool isReserve = false, isOdd = false, isRe = false;

	m_SubString.push_back(s[0]);
	s.push_back('\n');
	while (pos2 != s.size())
	{
		if (!isReserve && pos2 <= s.size() && pos2 > rePos)//aaaaaaaaaa
		{
			if (!isRe) rePos = pos2;
			if (s[pos2 - 1] == s[pos2])
			{
				tmpString += s[pos2++];
				isRe = true;
				continue;
			}
		}
		if (!isRe && pos >= 0 && s[pos2] == m_SubString[pos])// abb
		{
			tmpString.push_back(s[pos2++]);
			pos--;
			lastString[0] = {};
			isReserve = true;
		}
		else if (!isRe && s[pos2] == lastString[0])// aba
		{
			tmpString.push_back(s[pos2++]);
			pos -= 2;
			lastString[0] = {};
			isOdd = true;
			isReserve = true;
			isRe = false;
		}
		else// abc
		{
			if (tmpString.size())
			{
				if (isRe)
				{
					if (tmpString.size() + 1 > m_Result.size())
					{
						tmpString.push_back(m_SubString.back());
						m_Result.swap(tmpString);
					}
					tmpString.clear();
					isRe = false;
					std::swap(rePos, pos2);

					pos = m_SubString.size() - 1;
					lastString[0] = m_SubString[pos];
					continue;
				}
				m_SubString.push_back(*tmpString.begin());
				string reserve;
				for (auto var : tmpString)
				{
					reserve.insert(reserve.begin(), var);
				}
				if (isOdd)reserve.push_back(m_SubString.back());
				reserve += tmpString;

				if (reserve.size() > m_Result.size())
				{
					m_Result.swap(reserve);
				}

				reserve.clear();
				tmpString.clear();
				isOdd = false;
				isReserve = false;
			}
			else
			{
				m_SubString.push_back(s[pos2++]);
			}
			pos = m_SubString.size() - 1;
			lastString[0] = m_SubString[pos - 1];
		}
	}

	return m_Result;
}

void longestPalindrome::test()
{
	longestPalindrome::Solution sol5;

	string str = "aaaABaaABAaaa";

	string result = sol5.longestPalindrome(str);

	std::cout << result << '\n';
}
