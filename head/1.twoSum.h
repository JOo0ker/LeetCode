#pragma once

#include <vector>
#include <iostream>

using std::vector;

namespace twoSum {
	class Solution;
	void test();
}

class twoSum::Solution
{
public:
	vector<int> m_Result;
	vector<int> twoSum(vector<int>& nums, int target);
};