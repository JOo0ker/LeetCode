#include "1.twoSum.h"

int main()
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

	return 0;
}