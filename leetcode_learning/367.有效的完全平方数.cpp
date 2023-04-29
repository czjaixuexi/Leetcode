/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int x) {     
        if (x==1) return true;
        int left = 1;
        int right = x/2+1;
        while(left<=right){
            int middle = left + (right-left)/2;
            if(x/middle < middle){   // 等价于(middle*middle) > x(防溢出), 继续在左区间寻找，[left,middle-1]
                right = middle -1;
            }
            else if (x/middle >middle) //等价于(middle*middle)<x继续在右区间寻找，[middle+1,right]
            {
                left = middle+1;
            }   
            else{
                if(x%middle==0)//x/middle==middle时，且x能被middle整除，说明x为完全平方数
                { 
                return true; 
                }
                return false;
            }
            
        }
        return false;  //考虑x<=1的情况
    }
};
// @lc code=end

