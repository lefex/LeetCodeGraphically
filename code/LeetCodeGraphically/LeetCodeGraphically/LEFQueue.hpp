//
//  LEFQueue.hpp
//  LeetCodeGraphically
//
//  Created by wsy on 2019/5/26.
//  Copyright © 2019 WSY. All rights reserved.
//

#ifndef LEFQueue_hpp
#define LEFQueue_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class LefCircularDeque {
private:
    vector<int> buffer;
    int cnt;
    int k;
    int front;
    int tail;
public:
    LefCircularDeque(int k):buffer(k, 0) {
        k = k;
        front = 0;
        tail = 0;
        cnt = 0;
    }
    
    bool insertFront(int value) {
        if (cnt == k) {
            return false;
        }
        buffer[tail] = value;
        tail = (tail + 1) % k;
        ++cnt;
        
        return true;
    }
};

class MyDoubleEndCircularDeque {
private:
    vector<int> buffer;
    int cnt;
    int k;
    int front;
    int rear;
public:
    MyDoubleEndCircularDeque(int k): buffer(k, 0), cnt(0), k(k), front(k - 1), rear(0) {
        
    }
    // 头部插入
    bool insertFront(int value) {
        if (cnt == k) {
            return false;
        }
        buffer[front] = value;
        // 是环形，比如 front = 0 时
        front = (front - 1 + k) % k;
        ++cnt;
        
        return true;
    }
    // 尾部插入
    bool insertLast(int value) {
        if (cnt == k) {
            return false;
        }
        buffer[rear] = value;
        rear = (rear + 1) % k;
        ++cnt;
        
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % k;
        --cnt;
        
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        rear = (rear - 1 + k) % k;
        --cnt;
        
        return true;
    }
    // 获得头节点
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        // front 指向当前节点的上一节点
        return buffer[(front + 1) % k];
    }
    // 获得尾节点
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        // rear 指向的是尾节点的下一个节点
        return buffer[(rear - 1 + k) % k];
    }
    // 是否为空，当前大小为 0
    bool isEmpty() {
        return cnt == 0;
    }
    // 是否满了，当前大小和容量对比
    bool isFull() {
        return cnt == k;
    }
};

class MyCircularQueue {
    // 使用向量来表示队列中的元素
    vector<int> q;
    // 头、尾、队列大小
    int head, tail, N;
    // 队列是否为空
    bool empty;
public:
    // 初始化，大小为 k
    MyCircularQueue(int k) {
        // 初始化时，头和尾都指向队列的第一个位置
        head = 0;
        tail = 0;
        N = k;
        q = vector<int> (k);
        empty = true;
    }
    
    // 入队
    bool enQueue(int value) {
        if (isFull()) return false;
        empty = false;
        q[tail] = value;
        // 移动尾指针
        tail = (tail+1) % N;
        return true;
    }
    
    // 出队
    bool deQueue() {
        if (isEmpty()) return false;
        q[head] = 0;
        head = (head+1) % N;
        // 头和尾相等时判断为空
        if (head == tail) empty = true;
        return true;
    }
    
    // 头
    int Front() {
        if (isEmpty()) return -1;
        return q[head];
    }
    
    // 尾
    int Rear() {
        if (isEmpty()) return -1;
        return q[(tail-1+N)%N];
    }
    
    // 是否为空，使用一个临时变量来记录队列是否为空
    bool isEmpty() {
        return empty;
    }
    
    // 是否已满
    bool isFull() {
        return (empty) ? false : head == tail;
    }
};



#endif /* LEFQueue_hpp */
