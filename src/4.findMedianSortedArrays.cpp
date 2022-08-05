#include "4.findMedianSortedArrays.h"

double findMedianSortedArrays::Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	size_t i = 1, j = 1;
	int val1 = 0, val2 = 0;

	nums1.size() != 0 ? val1 = nums1[0] : val1 = INT_MAX;
	nums2.size() != 0 ? val2 = nums2[0] : val2 = INT_MAX;

	while (val1 != INT_MAX || val2 != INT_MAX)
	{
		bool use1 = val1 < val2 ? true : false;
		if (use1)
		{
			mV_Com.push_back(val1);
			i < nums1.size() ? val1 = nums1[i++] : val1 = INT_MAX;
 		}
		else
		{
			mV_Com.push_back(val2);
			j < nums2.size() ? val2 = nums2[j++]: val2 = INT_MAX;
		}
	}
	size_t total = nums1.size() + nums2.size();
	if (!total) return 0;
	total % 2 != 0 ? m_Result = static_cast<double>(mV_Com[total / 2]) : m_Result = (static_cast<double>(mV_Com[total / 2]) + static_cast<double>(mV_Com[total / 2 - 1]))/2;
	return m_Result;
}

void findMedianSortedArrays::test()
{
	vector<int> test1;
	test1.push_back(1);
	test1.push_back(3);

	vector<int> test2;
	test2.push_back(2);


	findMedianSortedArrays::Solution sol4;
	double result = sol4.findMedianSortedArrays(test1, test2);

	std::cout << result << '\n';
}
