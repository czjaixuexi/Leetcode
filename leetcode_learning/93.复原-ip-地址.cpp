// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem93.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    int pointnum = 0;
    bool isvalid(string s, int start, int end)
    {
        if(start > end) return false;
        //以0开头的数字不合法
        if(s[start] == '0' && start!=end) return false;

        int num = 0;
        for(int i = start; i <= end; i++){
            //非数字不合法
            if(s[i] > '9' || s[i] < '0') return false;

            //数字大于255不合法
            num = 10*num + (s[i] - '0');
            if(num > 255) return false;
        }   
        return true;
    }

    void backtrack(string &s,int start){
        if(pointnum == 3 && isvalid(s,start,s.size()-1)){
            res.push_back(s);
            return;
        }

        //横向遍历
        for(int i = start; i < s.size(); i++){
            if(isvalid(s,start,i)){
                s.insert(s.begin()+i+1,'.');
                pointnum++;
                
                backtrack(s,i+2); //纵向递归

                //回溯
                pointnum--;
                s.erase(s.begin()+i+1);
            }
            else break;
        }

    }

    vector<string> restoreIpAddresses(string s) {
        res.clear();
        backtrack(s,0);
        return res;
    }
};
// @lc code=end
