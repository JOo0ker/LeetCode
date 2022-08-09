#include "9.isPalindrome.h"
#include "..\..\head\9.isPalindrome.h"

bool isPalindrome::Solution::isPalindrome(int x)
{
    if (x < 0)return false;
    if (x < 10)return true;

    long long copy = x, tmp = 0;
    while (copy)
    {
        tmp = tmp * 10 + copy % 10;
        copy /= 10;
    }

    m_Result = (tmp == x);

    return m_Result;
}

void isPalindrome::test()
{
    isPalindrome::Solution sol9;
    
    while (true)
    {
        int tmp = 0;
        std::cout << "Please enter a number:";
        std::cin >> tmp;
        std::cout << tmp << (sol9.isPalindrome(tmp) ? " is" : " isn't") << " a palindrome.\n";
    }
}
