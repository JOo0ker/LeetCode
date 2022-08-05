#pragma once

#include <iostream>

namespace addTwoNumbers {
	class Solution;
	void test();
}

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	~ListNode()
	{
		if (this->next)
		{
			delete next;
		}
	}
};

class addTwoNumbers::Solution
{
public:
	bool m_End = false;
	bool m_Up = false;
	int m_Sum = 0;
	ListNode* m_Result = new ListNode(0);
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

	~Solution()
	{
		delete m_Result;
	}
};