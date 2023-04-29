/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int> &a,const vector<int> &b){
            if(a[0] == b[0]) return a[1] < b[1];
            else
                return a[0] >  b[0];
        }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        list<vector<int>> res;
        for(int i = 0;i<people.size();i++){
            int index = people[i][1];
            auto it = res.begin();
            while(index--){
                it++;
            }
            res.insert(it,people[i]);
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};
// @lc code=end

