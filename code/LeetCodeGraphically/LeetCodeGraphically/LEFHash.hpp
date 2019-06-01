//
//  LEFHash.hpp
//  LeetCodeGraphically
//
//  Created by wsy on 2019/5/29.
//  Copyright © 2019 WSY. All rights reserved.
//

#ifndef LEFHash_hpp
#define LEFHash_hpp

#include <stdio.h>
#include <vector>
#include <list>

using namespace std;

class MyHashMap {
    size_t m_size = 10000;
    vector<list<pair<int, int>>> m_data;
public:
    // 初始化，设置大小
    MyHashMap() {
        m_data.resize(m_size);
    }
    // 哈希函数
    int hashCode(int key) {
        return key % m_size;
    }
    
    // 根据 key 存储对应的 value，如果 key 已经存在，更新 value
    void put(int key, int value) {
        // 根据哈希函数找到对应的链表
        auto &list = m_data[hashCode(key)];
        for (auto & val : list) {
            // 如果已经存在，根据 key 来更新对应的值
            if (val.first == key) {
                val.second = value;
                return;
            }
        }
        // 插入链表的尾部
        list.emplace_back(key, value);
    }
    
    // 根据 key 来获取值
    int get(int key) {
        const auto &list = m_data[hashCode(key)];
        if (list.empty()) {
            return -1;
        }
        for (auto & val : list) {
            // 如果已经存在，找到了对应的值
            if (val.first == key) {
                return val.second;
            }
        }
        return -1;
    }
    
    // 根据 key 删除对应的值
    void remove(int key) {
        auto &list = m_data[hashCode(key)];
        // 找到节点后删除
        list.remove_if([key](auto n) {
            return n.first == key;
        });
    }
};

class My2HashMap {
    vector<list<pair<int,int>>> m_data;
    size_t m_size = 10000;
public:
    /** Initialize your data structure here. */
    My2HashMap() {
        m_data.resize(m_size);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto &list = m_data[key % m_size];
        for (auto & val : list) {
            if (val.first == key) {
                val.second = value;
                return;
            }
        }
        list.emplace_back(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        const auto &list = m_data[key % m_size];
        if (list.empty()) {
            return -1;
        }
        for (const auto & val : list) {
            if (val.first == key) {
                return val.second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto &list = m_data[key % m_size];
        list.remove_if([key](auto n) { return n.first == key; });
    }
};


#endif /* LEFHash_hpp */
