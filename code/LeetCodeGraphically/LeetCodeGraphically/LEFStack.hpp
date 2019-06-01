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
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= getMin())  s2.push(x);
    }
    void pop() {
        if (s1.top() == getMin())  s2.pop();
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int getMin() {
        return s2.top();
    }
};

class LMinStack {
public:
    stack<int> mainStack;
    stack<int> minStack;
    void push(int x) {
        mainStack.push(x);
        if (minStack.empty() || x <= getMin()) {
            minStack.push(x);
        }
    }
    
    void pop() {
        if (mainStack.top() == getMin()) {
            minStack.pop();
        }
        mainStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
       return minStack.top();
    }
};

#endif /* LEFStack_hpp */
