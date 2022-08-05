#include "1.twoSum.h"

vector<int> twoSum::Soluation::twoSum(vector<int>& nums, int target)
	{
	vector<int>::iterator it = nums.begin();
	for (; it != nums.end(); ++it)
	{
		for (vector<int>::iterator it2 = it + 1; it2 != nums.end(); ++it2)
		{
			if (*it + *it2 == target)
			{
				m_Result.push_back(static_cast<int>(distance(nums.begin(), it)));
				m_Result.push_back(static_cast<int>(distance(nums.begin(), it2)));
				return m_Result;
			}
		}
	}
	std::cout << "no such numbers.\n";
	exit(-1);
	}


void twoSum::test()
{
	twoSum::Soluation sol1;

	vector<int> test;
	test.push_back(11);
	test.push_back(22);
	test.push_back(33);
	test.push_back(44);
	test.push_back(55);
	test.push_back(66);

	vector<int> result = sol1.twoSum(test, 44 + 66);

	for (auto var : result)
	{
		std::cout << var << '\n';
	}
}