#include <vector>
#include <iostream>

using std::vector;

namespace twoSum {
	class Soluation;
}

class twoSum::Soluation
{
public:
	vector<int> m_Result;

	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int>::iterator it = nums.begin();
		for (; it != nums.end(); ++it)
		{
			for (vector<int>::iterator it2 = it + 1; it2 != nums.end(); ++it2)
			{
				if (*it + *it2 == target)
				{
					m_Result.push_back(distance(nums.begin(), it));
					m_Result.push_back(distance(nums.begin(), it2));
					return m_Result;
				}
			}
		}
		std::cout << "no such numbers.\n";
		exit(-1);
	}
};