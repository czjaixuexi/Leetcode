/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution
{
public:
    vector<string> res;
    string letter;
    string lettermap[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz", // 9}
    };
    void backtracking(string digits, int index)
    {
        if (index == digits.size())
        {
            res.push_back(letter);
            return;
        }
        int digit = digits[index] - '0';
        string letters = lettermap[digit];
        for (int i = 0; i < letters.size(); i++)
        {
            letter.push_back(letters[i]);
            backtracking(digits, index + 1);
            letter.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return res;
        }
        backtracking(digits, 0);
        return res;
    }
};
// @lc code=end
