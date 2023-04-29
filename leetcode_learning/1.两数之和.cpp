// @before-stub-for-debug-begin



// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
//通过哈希表存储，加快搜索的速度.

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); i++)
		{
			int value = target - nums[i];
			auto it = map.find(value);
            
			if (it != map.end() && it->second != i)
			{
				return { i,it->second };
			}
			map[nums[i]] = i; //若不存在，则插入数据
		}



		
		return {};
        
	}
};
// @lc code=end

