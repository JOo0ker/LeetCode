#pragma once

#include <vector>
#include <iostream>

using std::vector;

namespace findMedianSortedArrays{
	class Solution;
	void test();
}

class findMedianSortedArrays::Solution
{
public:
	double m_Result = 0;
	vector<int> mV_Com;

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
	double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2);
};