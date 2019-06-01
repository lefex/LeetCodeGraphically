//
//  LEFStack.hpp
//  LeetCodeGraphically
//
//  Created by wsy on 2019/5/26.
//  Copyright © 2019 WSY. All rights reserved.
//

#ifndef LEFStack_hpp
#define LEFStack_hpp

#include <stdio.h>
#include <stack>

using namespace std;

class MinStack {
public:
    // 主栈，保存了所有的元素
    stack<int> mainStack;
    // 保存比较小的元素
    stack<int> minStack;
    // 入栈
    void push(int x) {
        mainStack.push(x);
        if (minStack.empty() || x <= getMin()) {
            minStack.push(x);
        }
    }
    // 出栈
    void pop() {
        if (mainStack.top() == getMin()) {
            minStack.pop();
        }
        mainStack.pop();
    }
    // 栈顶
    int top() {
        return mainStack.top();
    }
    // 最小值
    int getMin() {
       return minStack.top();
    }
};

#endif /* LEFStack_hpp */
