#pragma once

#include <vector>
#include <iostream>

using std::vector;

namespace twoSum {
	class Soluation;
	void test();
}

class twoSum::Soluation
{
public:
	vector<int> m_Result;
	vector<int> twoSum(vector<int>& nums, int target);
};