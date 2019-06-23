//
//  MaxHeap.hpp
//  LeetCodeGraphically
//
//  Created by wsy on 2019/6/16.
//  Copyright © 2019 WSY. All rights reserved.
//

#ifndef MaxHeap_hpp
#define MaxHeap_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <deque>
#include <list>
#include <forward_list>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

class MaxHeap {
    vector<int> data;
public:    
    void printHeap() {
        for (auto v : data) {
            cout << v << endl;
        }
    }
    
    MaxHeap() {
        
    }
    
MaxHeap(int arr[], int n) {
    vector<int> v(arr, arr+n);
    data = v;
    for (int i = parent(n-1); i >= 0; i--) {
        shift_down(i);
    }
}
    
    int size() {
        return (int)data.size();
    }
    
    bool isEmpty() {
        return data.empty();
    }
    
    int parent(int index) {
        if (index == 0) {
            // No parent
            return -1;
        }
        return (index - 1) / 2;
    }
    
    int leftChlid(int index) {
        return 2 * index + 1;
    }
    
    int rightChlid(int index) {
        return 2 * index + 2;
    }
    
    void shift_up(int index) {
        // 不为根节点且父节点比根节点的值要小
        while (index > 0 && data[parent(index)] < data[index]) {
            swap(parent(index), index);
            // 依次堆当前节点的父节点进行上浮操作
            index = parent(index);
        }
    }
    
    void add(int value) {
        // 先加入向量中，然后对最后一个元素做上浮操作
        data.push_back(value);
        shift_up(size()-1);
    }
    
    void swap(int i, int j) {
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
    
    int pop_max() {
        if (size() == 0) {
            return -1;
        }
        // 只有一个元素直接 pop
        if (size() == 1) {
            int value = data[0];
            data.pop_back();
            return value;
        }
        int max = data[0];
        // 交换第一个和最后一个元素
        swap(0, size()-1);
        // 删除最后一个元素
        data.pop_back();
        shift_down(0);
        return max;
    }
    
    void shift_down(int index) {
        // 左孩子小于 data 的长度，说明没到头
        while (leftChlid(index) < size()) {
            int lIndex = leftChlid(index);
            int rIndex = rightChlid(index);
            // 找到左右孩子最大的元素
            int max = data[lIndex];
            if (rIndex < size() && data[rIndex] > max) {
                max = data[rIndex];
            }
            if (max > data[index]) {
                // 左孩子与父节点元素交换
                if (max == data[lIndex]) {
                    swap(lIndex, index);
                    index = lIndex;
                } else {
                    // 右孩子与父节点元素交换
                    swap(rIndex, index);
                    index = rIndex;
                }
            }  else {
                break;
            }
        }
    }
    
    
};


class PriorityQueue {
private:
    MaxHeap *maxHeap;
public:
    PriorityQueue() {
        maxHeap = new MaxHeap();
    }
    
    int size() {
        return maxHeap->size();
    }
    
    bool isEmpty() {
        return maxHeap->isEmpty();
    }
    
    int front() {
        return maxHeap->pop_max();
    }
    
    void enqueue(int e) {
        maxHeap->add(e);
    }
    
    int dequeue() {
        return maxHeap->pop_max();
    }
};

struct TopItem {
    int key;
    int value;
    TopItem(int k, int v) {
        key = k;
        value = v;
    }
    bool operator<(const TopItem& ohter) const {
        return value < ohter.value;
    }
};

class HeapSolution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
    
     vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map<int, int> map;
         for (auto v : nums) {
             int mv = map[v];
             mv += 1;
             map[v] = mv;
         }
         priority_queue<TopItem> pq;
         for (auto v : map) {
             TopItem item = TopItem(v.first, v.second);
             pq.push(item);
         }
         vector<int> ret;
         for (int i = 0; i < k; i++) {
             ret.push_back(pq.top().key);
             pq.pop();
         }
         for (auto v : ret) {
             cout << v << endl;
         }
         return ret;
     }
};

#endif /* MaxHeap_hpp */
