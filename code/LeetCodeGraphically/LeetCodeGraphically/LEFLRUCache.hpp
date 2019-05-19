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
    // 创建一个unordered_map
    std::unordered_map<Key, ListIterator> map;
    int capacity;
    int size;
    
    LRUCache(int maxCapacity) {
        this->capacity = 0;
        this->size = maxCapacity;
    }

    int get(Key key) {
        if (map.find(key) == map.end())
        {
            return -1;
        }
        else
        {
            
            ListIterator it = map[key];
            std::pair<Key, Value> p = *it;
            alist.erase(it);
            // We update our key's iterator
            alist.insert(alist.begin(), p);
            map[key] = alist.begin();
            return p.second;
        }
    }
    
    void put(int key, int value) {
        std::pair<Key, Value> p(key,value);
        if (map.find(key) == map.end())
        {
            if (this->capacity == this->size)
            {
                Key key_to_erase = (alist.back()).first;
                alist.pop_back();
                map.erase(key_to_erase);
            }
            else
            {
                capacity++;
            }
        }
        // If we already have this specific key, we just delete it and update it
        else
        {
            ListIterator it = map[key];
            alist.erase(it);
        }
        // We update our key's iterator
        alist.insert(alist.begin(), p);
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
