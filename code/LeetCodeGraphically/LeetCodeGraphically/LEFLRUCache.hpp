//
//  LEFLRUCache.hpp
//  LeetCodeGraphically
//
//  Created by wsy on 2019/5/10.
//  Copyright © 2019 WSY. All rights reserved.
//

#ifndef LEFLRUCache_hpp
#define LEFLRUCache_hpp

#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>

using Key = int;
using Value = int;
/**
 pair 包含了2个元素，first和second，和我们的元组差不多，不过它只有 2个元素
 list  list是一个线性双向链表结构，它的数据由若干个节点构成，每一个节点都包括一个信息块（即实际存储的数据）、一个前驱指针和一个后驱指针。
 https://www.cnblogs.com/loleina/p/5179677.html
 */
using ListIterator = std::list<std::pair<Key,Value> >::iterator;

class LRUCache {
public:
    // 创建一个元素为 pair 类型的 list
    std::list<std::pair<Key,Value> > alist;
    // 创建一个 unordered_map，value 为一个迭代器
    std::unordered_map<Key, ListIterator> map;
    // 当前大小
    int capacity;
    // 容量
    int size;
    
    // 初始化
    LRUCache(int maxCapacity) {
        this->capacity = 0;
        this->size = maxCapacity;
    }

    // 根据 key 获取对应的 value
    int get(Key key) {
        // 如果没找到，返回 -1
        if (map.find(key) == map.end()) {
            return -1;
        }
        else {
            // 找到了，先找到迭代器
            ListIterator it = map[key];
            std::pair<Key, Value> p = *it;
            // 删除这个节点
            alist.erase(it);
            // 把 p 插入到开始位置
            alist.insert(alist.begin(), p);
            // 给 map 重新赋值
            map[key] = alist.begin();
            // 返回 p 对应的值
            return p.second;
        }
    }
    
    // 插入新值
    void put(int key, int value) {
        // 创建一个新的 pair
        std::pair<Key, Value> p(key,value);
        // 如果没找到
        if (map.find(key) == map.end()) {
            // 达到了最大限制
            if (this->capacity == this->size) {
                // 找到链表最后一个值的 key，用来删除 map 中的值
                Key key_to_erase = (alist.back()).first;
                // 把链表的最后一个移除，
                alist.pop_back();
                // 移除 map 中 key 对应的值
                map.erase(key_to_erase);
            } else {
                // 扩大当前的值
                capacity++;
            }
        } else {
            // 找到了这个值，把它删除
            ListIterator it = map[key];
            alist.erase(it);
        }
        // 把p插入到首位
        alist.insert(alist.begin(), p);
        // 插入到 map 中
        map[key] = alist.begin();
    }
    
    void useList() {
        /**
         C++ 中的 List
         */
        using namespace std;
        list<string> nameList;
        nameList.push_front(" I ");
        nameList.push_back(" am ");
        nameList.push_back(" lefex");
        
        list<string>::iterator nameIterator;
        for (nameIterator = nameList.begin(); nameIterator != nameList.end(); nameIterator++) {
            cout << *nameIterator;
        }
        
    }
};

#endif /* LEFLRUCache_hpp */
