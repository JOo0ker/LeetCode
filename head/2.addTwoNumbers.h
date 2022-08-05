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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		if (l1 == nullptr || l2 == nullptr) return nullptr;
		ListNode* first = m_Result;
		while (true)
		{
			int val1 = 0, val2 = 0;
			if (l1 != nullptr)
			{
				val1 = l1->val;
				l1 = l1->next;
			}
			if (l2 != nullptr)
			{
				val2 = l2->val;
				l2 = l2->next;
			}

			m_Sum = 0;
			m_Sum = val1 + val2 + (int)m_Up;
			m_Up = m_Sum / 10;
			m_Result->next = new ListNode(m_Sum % 10);

			if(l1 == nullptr && l2 == nullptr && m_Up == false) break;
			m_Result = m_Result->next;
		}
		m_Result = first;
		return m_Result->next;
	}

	~Solution()
	{
		delete m_Result;
	}
};

void addTwoNumbers::test()
{
	int num1 = 123;
	int num2 = 14356;

	ListNode* l1 = new ListNode(num1 % 10);
	ListNode* l2 = new ListNode(num2 % 10);
	ListNode* tmp = l1;
	for (num1 /= 10; num1; num1 /= 10)
	{
		tmp->next = new ListNode(num1 % 10);
		tmp = tmp->next;
	}
	tmp = l1;
	while (tmp)
	{
		std::cout << tmp->val << " ";
		tmp = tmp->next;
	}

	tmp = l2;
	for (num2 /= 10; num2; num2 /= 10)
	{
		tmp->next = new ListNode(num2 % 10);
		tmp = tmp->next;
	}
	std::cout << '\n';
	tmp = l2;
	while (tmp)
	{
		std::cout << tmp->val << " ";
		tmp = tmp->next;
	}

	addTwoNumbers::Solution sol2;

	tmp = sol2.addTwoNumbers(l1, l2);
	std::cout << '\n';
	while (tmp)
	{
		std::cout << tmp->val << " ";
		tmp = tmp->next;
	}
}