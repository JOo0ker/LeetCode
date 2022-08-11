#include "11.maxArea.h"

int maxArea::Solution::maxArea(vector<int>& height)
{
	if (height.size()<=1) return 0;
	if (height.size() == 2) return std::min(height[0], height[1]);

	int i = 0, j = height.size() - 1;

	int maxNum = height[i], remain = height[j], tmp = 0;

	bool isBack = true;

	int total = 0;

	while (i<=j)
	{
		if (isBack)
		{
			tmp = height[j--];
		}
		else
		{
			tmp = height[i++];
		}

		if (tmp < remain) continue;

		remain = tmp;
		int newTotal = std::min(tmp, maxNum)* (j - i + 2);

		if (maxNum < remain)
		{
			tmp = maxNum;
			maxNum = remain;
			remain = tmp;
			isBack = !isBack;
		}

		total = std::max(total, newTotal);
	}

	m_Result = total;

	return m_Result;
}

void maxArea::test()
{
	maxArea::Solution sol11;

	vector<int> test;
	test.push_back(2);
	test.push_back(3);
	//test.push_back(4);
	//test.push_back(5);
	//test.push_back(18);
	//test.push_back(17);
	//test.push_back(6);
	//test.push_back(3);
	//test.push_back(7);

	std::cout << sol11.maxArea(test) << '\n';
}
