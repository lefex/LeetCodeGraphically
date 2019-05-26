//
//  LEFLFUCache.hpp
//  LeetCodeGraphically
//
//  Created by wsy on 2019/5/25.
//  Copyright © 2019 WSY. All rights reserved.
//

#ifndef LEFLFUCache_hpp
#define LEFLFUCache_hpp

#include <stdio.h>
#include <unordered_map>
#include <list>
#import <iostream>


using std::cout;
using std::endl;
using namespace std;

struct LFUNode {
    int value;
    int freq;
    list<int>::iterator iter;
};

class LLFUCache {
    int capacity;
    int size;
    int minFreq;
    unordered_map<int, LFUNode> linkedMap;
    unordered_map<int, list<int>> freqListMap;
public:
    LLFUCache(int cap) {
        capacity = cap;
        size = 0;
    }
    
    int get(int key) {
        if (linkedMap.find(key) == linkedMap.end()) {
            return -1;
        }
        LFUNode node = linkedMap[key];
        list<int> fList = freqListMap[node.freq];
        fList.erase(node.iter);
        node.freq += 1;
        node.iter = fList.begin();
        linkedMap[key] = node;
        
        int skey = node.freq;
        if (freqListMap.find(skey) != freqListMap.end()) {
            list<int> sList = freqListMap[skey];
            sList.insert(node.iter, key);
            freqListMap[skey] = sList;
        } else {
            list<int> sList;
            sList.push_back(key);
            freqListMap[skey] = sList;
        }
       
        if (freqListMap.find(minFreq) == freqListMap.end()) {
            minFreq += 1;
        }
        return node.value;
    }
    
    void put(int key, int value) {
        if (get(key) != -1) {
            return;
        }
        
        if (size + 1 > capacity) {
            // 超出容量限制
            list<int> minFreqList = freqListMap[minFreq];
            minFreqList.pop_back();
            size -= 1;
        }
        
        if (freqListMap.find(1) != freqListMap.end()) {
            // 没有freq对应的链表
            list<int> fList;
            fList.insert(fList.begin(), 1);
            freqListMap[1] = fList;
            LFUNode node = {value, 1, fList.begin()};
            linkedMap[key] = node;
        } else {
            // 找到了 freq对应的链表
            list<int> fList = freqListMap[1];
            fList.insert(fList.begin(), 1);
            LFUNode node = {value, 1, fList.begin()};
            linkedMap[key] = node;
        }
        minFreq = 1;
        size += 1;
    }
};

class LEFLFUCache {
    int capacity;
    int size;
    int minFreq;
    // key {value, freq} 键：{值，使用频次}
    unordered_map<int, pair<int, int>> linkedMap;
    // key iterator 键: 链表中的位置
    unordered_map<int, list<int>::iterator> iterMap;
    // 使用次数和链表
    unordered_map<int, list<int>> freqListMap;
public:
    LEFLFUCache(int capacity) {
        capacity = capacity;
        size = 0;
    }
    
    int get(int key) {
        cout << "get: " << key << endl;
        // 没找到 key 对应的值
        if(linkedMap.count(key) == 0) {
            cout << "not found" << endl;
            return -1;
        }
        
        // freq = m[key].second 使用频次，fm[freq] 使用频次对应的链表, mIter[key] 在链表中的位置
        int freq = linkedMap[key].second;
        if (freqListMap.find(freq) != freqListMap.end()) {
            list<int> freqList = freqListMap[freq];
            for(unordered_map<int,list<int>::iterator>::iterator iter= iterMap.begin(); iter!=iterMap.end(); iter++) {
//                cout << iter->second << endl;
//                cout << "key=" << iter->first << " and value=" << iter->second << endl;

            }
//            freqList.erase(iterMap[key]);
        }
        
        // 使用频次加 1
        freq += 1;
        linkedMap[key].second = freq;
        list<int> addFreqList = freqListMap[freq];
        // 最新的放到最后
        addFreqList.push_back(key);
        iterMap[key] = addFreqList.end();
        
        // 保存最小值，淘汰时使用
        if(freqListMap[minFreq].size() == 0) {
            minFreq++;
        }
        
        return linkedMap[key].first;
    }
    
    void put(int key, int value) {
        if(capacity <= 0) {
            return;
        }
        
        // 已经存在了，使用频次 +1，返回值
        int storeValue = get(key);
        if(storeValue != -1) {
            linkedMap[key].first = value;
            return;
        }
        
        // 超出最大容量
        if(size >= capacity ) {
            // 删除使用次数最少的
            int eraseKey = freqListMap[minFreq].front();
            linkedMap.erase(eraseKey);
            iterMap.erase(eraseKey);
            freqListMap[minFreq].pop_front();
            size--;
        }
        
        linkedMap[key]={value, 1};
        freqListMap[1].push_back(key);
        iterMap[key] = --freqListMap[1].end();
        minFreq = 1;
        size++;
    }
};

class LFUCache {
public:
    int cap;
    //当前容量
    int size;
    // 最小的 freq，删除元素时需要知道该删除哪个链表
    int minFreq;
    // 保存 value和freq
    unordered_map<int, pair<int, int>> valueFreqMap;
    // 保存 key 在链表中的位置
    unordered_map<int, list<int>::iterator> iterMap;
    // freq 对应的链表
    unordered_map<int, list<int>> freqListMap;
    
    // 初始化
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(valueFreqMap.count(key)==0) return -1;
        // 删除链表中的节点
        freqListMap[valueFreqMap[key].second].erase(iterMap[key]);
        // 增加使用频次
        valueFreqMap[key].second++;
        // 把 key 放到链表的末尾
        freqListMap[valueFreqMap[key].second].push_back(key);
        // 记录 key 值链表中的位置
        iterMap[key] = --freqListMap[valueFreqMap[key].second].end();
        // 修改最小 freq
        if(freqListMap[minFreq].size() == 0)
            minFreq++;
        
        return valueFreqMap[key].first;
    }
    
    void put(int key, int value) {
        if(cap <= 0) return;
        // get 方法会修改使用频次
        int storedValue=get(key);
        if(storedValue != -1) {
            valueFreqMap[key].first = value;
            return;
        }
        
        // 超出容量限制，该删除了
        if(size >= cap ){
            valueFreqMap.erase( freqListMap[minFreq].front() );
            iterMap.erase( freqListMap[minFreq].front() );
            freqListMap[minFreq].pop_front();
            size--;
        }
        
        // 保存到各个 map 中
        valueFreqMap[key] = {value, 1};
        freqListMap[1].push_back(key);
        // 最后一个位置
        iterMap[key] = --freqListMap[1].end();
        minFreq = 1;
        size++;
    }
};
#endif /* LEFLFUCache_hpp */
