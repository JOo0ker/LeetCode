#include "5.longestPalindrome.h"

string longestPalindrome::Solution::longestPalindrome(string s)
{
	if (!s.size()) return string("");// ��
	if (s.size() == 1) return s;// a
#if 0// myResult

	int	 pos = 0 // ���ַ���λ��
		, pos2 = 1// ԭ�ַ���λ��
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
#else// manacher
	string added = {};
	for (auto var : s)
	{
		added.push_back('#');
		added.push_back(var);
	}
	added.push_back('#');

	long long R = -1, C = -1;
	long long max = 0, pos = 0;
	vector<long long> radius;
	radius.resize(added.size());
	for (int i = 0; i < added.size(); i++)
	{
		radius[i] = (R > i ?											// �ж��Ƿ��Ѿ��ڶԳ�λ�ü��������					      ��    C    ��  R(ʣ��2����֮ǰ����Ϊ4��
			std::min(radius[2 * C - i], R - i + 1) :					// ǰ��μ���Ļ��ĳ����뵱ǰʣ����ĳ��Ƚ��бȽϣ���:	ab aa b aa b aa b aa c
			1);															//												01 00 4 00 5 00 ^
		while (i + radius[i] < added.size()								// ֱ��β�ַ�
			&& i - radius[i] > -1)										// ֱ�����ַ�
		{
			if (added[i - radius[i]] == added[i + radius[i]])			// �Գ�λ���ַ��Ƚ�
			{
				radius[i]++;											// ���ӻ��İ뾶
			}
			else
			{
				break;
			}
		}
		if (i + radius[i] > R)											// ����Ƿ�Խ�磨������ǰ�Ļ��İ뾶��
		{
			R = i + radius[i] - 1;										// ������չ�߽�
			C = i;														// ���µ�ǰ�Գ�����
		}

		if (radius[i] - 1 > max)
		{
			max = radius[i] - 1;
			pos = (C - radius[i] + 1)/2;
		}
	}

	m_Result = s.substr(pos, max);

#endif
	return m_Result;
}

void longestPalindrome::test()
{
	longestPalindrome::Solution sol5;

	string str = "";
	std::cout << "The emtpy input :" << sol5.longestPalindrome(str) << '\n';
	while (true)
	{
		std::cout << "Enter a line:";
		std::cin >> str;

		string result = sol5.longestPalindrome(str);

		std::cout <<"The longest palindrome is:" << result << '\n';
	}
}
