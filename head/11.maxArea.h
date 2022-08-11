#pragma once

#include <vector>
#include <iostream>

using std::vector;

namespace maxArea{
	class Solution;
	void test();
}

class maxArea::Solution
{
public:
	int m_Result;
	int maxArea(vector<int>& height);
};

//给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
//
//找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//
//返回容器可以储存的最大水量。
//
//说明：你不能倾斜容器。

//n == height.length
//2 <= n <= 105
//0 <= height[i] <= 104

