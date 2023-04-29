/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x-1;
        while(left<=right){
            int middle = left + (right-left)/2;
            if(x/middle < middle){   // 等价于(middle*middle) > x(防溢出), 继续在左区间寻找，[left,middle-1]
                if(x/(middle-1)>middle-1)    //等价于(middle-1)*(middle-1)<x 
                {return middle -1;}         //说明middle-1就是 (int)算数平方根
                right = middle -1;
            }
            else if (x/middle >middle) //等价于(middle*middle)<x继续在右区间寻找，[middle+1,right]
            {
                if(x/(middle+1)<middle+1) //等价于(middle+1)*(middle+1)>x
                {return middle;}           //说明middle就是 (int)算数平方根
                left = middle+1;
            }   
            else
            return middle;
        }
        return x;  //考虑x<=1的情况
    }
};
// @lc code=end

