// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem860.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0, twenty = 0; //用于记录每种货币的数量
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
                five++; //
            else if (bills[i] == 10)
            {
                ten++;
                if (five-- > 0)
                    continue;
                else
                    return false;
            }
            else if (bills[i] == 20)
            {
                twenty++;

                if (ten > 0 && five > 0)
                {
                    five--;
                    ten--;
                    continue;
                }

                if (five > 2)
                {
                    five -= 3;
                    continue;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
