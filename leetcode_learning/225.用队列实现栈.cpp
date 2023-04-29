/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    queue<int> que1;
    queue<int> que2; //辅助队列用来备份
    MyStack() {

    }
    
    void push(int x) {
        que1.push(x);
    }
    
    int pop() {
        int res = que1.back();
        int size = que1.size();
        size--;
        //将que1中除了最后一个元素外，都复制到que2
        while(size--){
            que2.push(que1.front());
            que1.pop();
        }
        que1.pop();
        que1 = que2;
        //清空que2
        while(!que2.empty())
        {
            que2.pop();
        }
        return res;
    }
    
    int top() {
        return que1.back();
    }
    
    bool empty() {
        return que1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

